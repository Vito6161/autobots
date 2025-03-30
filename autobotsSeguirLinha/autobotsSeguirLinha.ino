#include <robo_hardware2.h>
#include "lerRefletancia.h"

// autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots //

#define velFrente 25 
#define velVirar 25
#define velDireito 26

const int portaSensorMaisDir = 0;
const int portaSensorDir = 1;
const int portaSensorEsq = 2;
const int portaSensorMaisEsq = 3;

digitalWrite(portaSensorMaisDir, HIGH);
digitalWrite(portaSensorDir, HIGH);
digitalWrite(portaSensorMaisEsq, HIGH);
digitalWrite(portaSensorEsq, HIGH);

lerRefletancia refle;

void setup()
{
  robo.configurar();
}

void loop()
{
  refle.atualizarValoresRef();

  if(refle.Frente())
  {
    robo.acionarMotores(velFrente, velFrente);
  }
  else if(refle.Direita())
  {
    robo.acionarMotores(velVirar,-velDireito);
  }
  else if(refle.Esquerda())
  {
    robo.acionarMotores(-velVirar, velDireito);
  }
  else if(refle.Re())
  {
    robo.acionarMotores(-velFrente, -velDireito);
  }
  else
  {
    robo.acionarMotores(0,0);
  }
}