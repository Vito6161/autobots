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

#define velFrente 25 //25
#define velVirar 25

#define velDireito 26 // 27

#define espera 780 //750
#define esperaFrente 870 ///850

float valorSensorDir;
float valorSensorEsq;
float valorSensorMaisEsq;
float valorSensorMaisDir;
float valorSensorSonar;

const int portaSensorMaisDir = 0;
const int portaSensorDir = 1;
const int portaSensorEsq = 2;
const int portaSensorMaisEsq = 3;

RGB valSensorRGBEsquerdo;
RGB valSensorRGBDireito;
bool RGBEsquerdo, RGBDireito;

void setup(){
	robo.configurar();
}

void loop()
{

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

  if(pppp())
  {
    BecoSemSaida();
  }


  if(valorSensorSonar <= 5)
  {
    DesviarDireita();
    
  }
  
	
	if(bbbb() || bppb() || pppp() || pbpb() || bpbp() || pbbp()){
		robo.acionarMotores(velFrente, velFrente);	//ANDA PRA FRENTE
    LigarJuntos();
	}
	
	else if (bppp() || bbpp() || bbbp() || bbpb()){
 		robo.acionarMotores(velVirar,-velDireito);	//ANDA PRA DIREITA
    LigarVerde();
	}
	
	else if (pppb() || ppbb() || pbbb() || bpbb()){
		robo.acionarMotores(-velVirar, velDireito);	//ANDA PRA ESQUERDA
    LigarAzul();
	}
 else if (pbbp()){
    robo.acionarMotores(-velFrente, -velDireito);
    delay(50);
  
 }
	
	else{ //Identifica se os dois sensores viram preto
		robo.acionarMotores(0,0);
    ApagarLeds();
	}
 

}

inline bool pbbp() {return(valorSensorMaisEsq < DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorMaisDir < DIVISOR_BRANCO_PRETO);}
inline bool pppp() {return(valorSensorMaisEsq < DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorMaisDir < DIVISOR_BRANCO_PRETO);}
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
inline bool pbpb() {return(valorSensorMaisEsq < DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorMaisDir > DIVISOR_BRANCO_PRETO);}
inline bool bpbp() {return(valorSensorMaisEsq > DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorMaisDir < DIVISOR_BRANCO_PRETO);}

void DesviarDireita() 
{
 
    robo.acionarMotores(0,0); // identifica o objeto e para o robo
    delay(espera);

    robo.acionarMotores(velFrente, -velDireito); // gira o robo pra direita   
    delay(espera);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, velDireito); //anda pra frente depois de girar para poder desviar do obstaculo
    delay(esperaFrente);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(-velFrente, velDireito); // gira o robo pra esquerda
    delay(espera);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, velDireito); //anda pra frente depois de girar para poder desviar do obstaculo
    delay(esperaFrente);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(-velFrente, velDireito); // gira o robo pra esquerda
    delay(espera);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, velDireito); //anda pra frente depois de girar para poder desviar do obstaculo
    delay(750);
  
    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, -velDireito); // gira o robo pra direita
    delay(espera);
    
}

void DesviarEsquerda() 
{
  
    robo.acionarMotores(0,0); // identifica o objeto e para o robo
    delay(espera);

    robo.acionarMotores(velFrente, -velDireito); // gira o robo pra direita   
    delay(espera);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, velDireito); //anda pra frente depois de girar para poder desviar do obstaculo
    delay(esperaFrente);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(-velFrente, velDireito); // gira o robo pra esquerda
    delay(espera);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, velDireito); //anda pra frente depois de girar para poder desviar do obstaculo
    delay(esperaFrente);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(-velFrente, velDireito); // gira o robo pra esquerda
    delay(espera);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, velDireito); //anda pra frente depois de girar para poder desviar do obstaculo
    delay(750);
  
    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, -velDireito); // gira o robo pra direita
    delay(espera);
    
}

void BecoSemSaida()
{
//vcc sensor esquerdo: 2 | vcc sensor direito: 3
    robo.acionarMotores(velFrente, velDireito);
    delay(7);
    robo.acionarMotores(0, 0);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    delay(50);
    

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW); //liga o esquerdo e desliga o direito

    valSensorRGBEsquerdo = robo.getRGBEsquerdo();

    if(valSensorRGBEsquerdo.verde > valSensorRGBEsquerdo.azul && valSensorRGBEsquerdo.verde > valSensorRGBEsquerdo.vermelho)
    {
      RGBEsquerdo = true;
    } 
    else
    {
      RGBEsquerdo = false;
    }

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH); //liga o direito e desliga o esquerdo

    valSensorRGBDireito = robo.getRGBDireito();

    if(valSensorRGBDireito.verde > valSensorRGBDireito.azul && valSensorRGBDireito.verde > valSensorRGBDireito.vermelho)
    {
      RGBDireito = true;
    } 
    else
    {
      RGBDireito = false;
    }

    if(RGBEsquerdo == true && RGBDireito == true) //os 2 sensores detectaram verde e o robô deve voltar
    {
      robo.acionarMotores(velFrente, -velDireito);
      delay(1400);
    }

    if(RGBEsquerdo == true && RGBDireito == false) // esquerda verde e direita nada, vira pra esquerda
    {
      robo.acionarMotores(-velFrente, velDireito);
      delay(200);
    }

    if(RGBEsquerdo == false && RGBDireito == true) // esquerda nada e direita verde, vira pra direita
    {
      robo.acionarMotores(velFrente, -velDireito);
      delay(250);
    }

    if(RGBEsquerdo == false && RGBDireito == false) //os 2 sensores não detectaram nada e o robô deve seguir em frente
    {
      robo.acionarMotores(velFrente, velDireito);
      delay(250);
    } 
    else {
      LigarJuntos();
      delay(300);
      ApagarLeds();
      robo.acionarMotores(velFrente, velDireito);
    }
    
  
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
