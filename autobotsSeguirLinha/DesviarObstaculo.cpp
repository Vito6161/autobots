#include "DesviarObstaculo.h"

void Desvio::DesviarEsquerda()
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Desvio::DesviarDireita()
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

void Desvio::atualizarValorSonar()
{
  valorSonar = robo.lerSensorSonarFrontal();
}