#include "DesviarObstaculo.h"
#include <robo_hardware2.h>

void Desvio::DesviarObstaculo(int sentido)
{

  velEsq = velFrente * sentido;
  velDir = -velEsq;
    
  for(int i = 0; i < esperaCiclos; i++) //primeiro ciclo: sai da pista e vai ate o obstaculo
  {
    robo.acionarMotores(velEsq, velDir);
    delay(esperaVirar); //gira um pouco

    robo.acionarMotores(velFrente, velFrente);
    delay(esperaFrente); // anda um pouco pra frente
  }


  for(int i = 0; i < esperaCiclos; i++) // segundo ciclo: volta ate a pista
  {
    robo.acionarMotores(velEsq, velDir);
    delay(esperaVirar); //gira um pouco

    robo.acionarMotores(velFrente, velFrente);
    delay(esperaFrente); // anda um pouco pra frente
  }
  
}


void Desvio::AtualizarValorSonar()
{
  valorSonar = robo.lerSensorSonarFrontal();
}
