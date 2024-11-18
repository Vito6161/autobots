#include <robo_hardware2.h> 
#include <Servo.h>

// autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots //

//-----PINOS PARA LIGAR MOTORES-----//
//Motor1:
//pino1 PWM_RODA_DIREITA 	6
//pino2 SENTIDO_RODA_DIREITA 	7
//
//Motor2:
//pino1 PWM_RODA_ESQUERDA 	5
//pino2 SENTIDO_RODA_ESQUERDA	4
//-----PINOS PARA LIGAR MOTORES-----//

//-----PINOS PARA SENSORES REFLETANCIA-----//
//SENSOR_LINHA_MAIS_ESQUERDO	    A3
//SENSOR_LINHA_ESQUERDO			    A2
//SENSOR_LINHA_DIREITO			    A1	
//SENSOR_LINHA_MAIS_DIREITO			A0	
//-----PINOS PARA SENSORES REFLETANCIA-----//


#define DIVISOR_BRANCO_PRETO 90

#define velFrente 25
#define velVirar 30

float valorSensorDir;
float valorSensorEsq;
float valorSensorMaisEsq;
float valorSensorMaisDir;
float valorSensorSonar;

const int portaSensorMaisDir = 0;
const int portaSensorDir = 1;
const int portaSensorEsq = 2;
const int portaSensorMaisEsq = 3;

void setup(){
	robo.configurar();
}

void loop(){
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
	valorSensorEsq = robo.lerSensorLinhaEsq(); //Le o valor do sensor esquerdo e coloca dentro da variavel valor_sensor_esq
	valorSensorDir = robo.lerSensorLinhaDir(); //Le o valor do sensor direito e coloca dentro da variavel valor_sensor_dir
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
  valorSensorSonar = robo.lerSensorSonarFrontal();

 //LIGA TODOS OS SENSORES DE REFLETÂNCIA
  digitalWrite(portaSensorMaisDir, HIGH);
  digitalWrite(portaSensorDir, HIGH);
  digitalWrite(portaSensorMaisEsq, HIGH);
  digitalWrite(portaSensorEsq, HIGH);

  if(valorSensorSonar <= 5)
  {
    Desviar();
    LigarJuntos();
    delay(50);
    ApagarLeds();
    delay(50);
    LigarJuntos();
    delay(50);
    ApagarLeds();
    delay(50);
    LigarJuntos();
    delay(50);
    ApagarLeds();
    delay(5000);
  }
  
	
	if(bbbb() || bppb() || bpbb() || bbpb()){
		robo.acionarMotores(velFrente, velFrente);	//ANDA PRA FRENTE
    LigarJuntos();
	}
	
	else if (bppp() || bbpp() || bbbp()){
 		robo.acionarMotores(velVirar,-velVirar);	//ANDA PRA DIREITA
    LigarVerde();
	}
	
	else if (pppb() || ppbb() || pbbb()){
		robo.acionarMotores(-velVirar, velVirar);	//ANDA PRA ESQUERDA
    LigarAzul();
	}
	
	else{ //Identifica se os dois sensores viram preto
		robo.acionarMotores(0,0);
    ApagarLeds();
	}
 

}

//inline bool pppp() {valorSensorMaisEsq < DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorMaisDir < DIVISOR_BRANCO_PRETO}
inline bool pppb() {return(valorSensorMaisEsq < DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorMaisDir > DIVISOR_BRANCO_PRETO);}
inline bool ppbb() {return(valorSensorMaisEsq < DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorMaisDir > DIVISOR_BRANCO_PRETO);}
inline bool pbbb() {return(valorSensorMaisEsq < DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorMaisDir > DIVISOR_BRANCO_PRETO);}
inline bool bppp() {return(valorSensorMaisEsq > DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorMaisDir < DIVISOR_BRANCO_PRETO);}
inline bool bbpp() {return(valorSensorMaisEsq > DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorMaisDir < DIVISOR_BRANCO_PRETO);}
inline bool bbbp() {return(valorSensorMaisEsq > DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorMaisDir < DIVISOR_BRANCO_PRETO);}
inline bool bppb() {return(valorSensorMaisEsq > DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorMaisDir > DIVISOR_BRANCO_PRETO);}
inline bool bbbb() {return(valorSensorMaisEsq > DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorMaisDir > DIVISOR_BRANCO_PRETO);}
inline bool bbpb() {return(valorSensorMaisEsq > DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorMaisDir > DIVISOR_BRANCO_PRETO);}
inline bool bpbb() {return(valorSensorMaisEsq > DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorMaisDir > DIVISOR_BRANCO_PRETO);}

void Desviar() 
{
    int velViradaDesviar = 30;
    int velDesviar = 35;
  
    robo.acionarMotores(0,0); // identifica o objeto e para o robo
    delay(500);
    
    robo.acionarMotores(velViradaDesviar, -velViradaDesviar); // gira o robo pra direita
    delay(50);

    robo.acionarMotores(velDesviar, velDesviar); //anda pra frente depois de girar para poder desviar do obstaculo
    delay(50);

    robo.acionarMotores(0,0);
}

void LigarJuntos() 
{
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
}


void ApagarLeds()
{
    digitalWrite(1, LOW);
    digitalWrite(0, LOW);
}

void LigarVerde()
{
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
}

void LigarAzul()
{
    digitalWrite(1, LOW);
    digitalWrite(0, HIGH);
}
