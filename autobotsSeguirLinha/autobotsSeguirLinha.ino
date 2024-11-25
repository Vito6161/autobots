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
#define velVirar 25

#define velDireito 27

//#define velViradaDesviar 30
//#define velDesviar 25

#define espera 675 //estava em 650, agora esta em 675
#define esperaFrente 1000 // so funciona se, ao colocar a bateria na fonte a uma D.D.P de 11V, a amperagem deve estar entre 1.1 ou 0.8 amperes.
//#define esperaParado 1000

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


  if(valorSensorSonar <= 2.8)
  {
    DesviarDireita();
    
  }
  
	
	if(bbbb() || bppb()|| pppp()){
		robo.acionarMotores(velFrente, velDireito);	//ANDA PRA FRENTE
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
	
	else{ //Identifica se os dois sensores viram preto
		robo.acionarMotores(0,0);
    ApagarLeds();
	}
 

}

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

    robo.acionarMotores(-velFrente, 23); // gira o robo pra esquerda
    delay(espera);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, velDireito); //anda pra frente depois de girar para poder desviar do obstaculo
    delay(esperaFrente);
  
    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, -velDireito); // gira o robo pra direita
    delay(espera);
    
}

void DesviarEsquerda() 
{
 
    robo.acionarMotores(0,0); // identifica o objeto e para o robo
    delay(espera);

    robo.acionarMotores(-velFrente, velDireito); // gira o robo pra esquerda  
    delay(espera);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, velDireito); //anda pra frente depois de girar para poder desviar do obstaculo
    delay(esperaFrente);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, -velDireito); // gira o robo pra direita
    delay(espera);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, velDireito); //anda pra frente depois de girar para poder desviar do obstaculo
    delay(esperaFrente);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, -23); // gira o robo pra direita
    delay(espera);

    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(velFrente, velDireito); //anda pra frente depois de girar para poder desviar do obstaculo
    delay(esperaFrente);
  
    robo.acionarMotores(0,0);
    delay(espera);

    robo.acionarMotores(-velFrente, velDireito); // gira o robo pra esquerda
    delay(espera);
    
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
