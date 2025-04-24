#include <robo_hardware2.h>
#include "lerRefletancia.h"
#include "DesviarObstaculo.h"

// autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots autobots //

#define velFrente 25 
#define velVirar 25
#define velDireito 26

const int portaSensorMaisDir = 0;
const int portaSensorDir = 1;
const int portaSensorEsq = 2;
const int portaSensorMaisEsq = 3;

lerRefletancia refle;
Desvio desvi;

void setup()
{
  robo.configurar();
}

void loop()
{
  refle.atualizarValoresRef();
  desvi.AtualizarValorSonar();

  if(desvi.valorSonar <= 4)
  {
    desvi.DesviarObstaculo(1);
  }


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

  digitalWrite(portaSensorMaisDir, HIGH);
  digitalWrite(portaSensorDir, HIGH);
  digitalWrite(portaSensorMaisEsq, HIGH);
  digitalWrite(portaSensorEsq, HIGH);
}
