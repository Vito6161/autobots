#include <robo_hardware2.h>

class Desvio
{
  public:
    
    void DesviarObstaculo(int sentido);
    void AtualizarValorSonar();

    float valorSonar;

  private: 

    int velFrente = 25;
    int velEsq;
    int velDir;
    
    int esperaCiclos = 500;
    int esperaFrente = 60;
    int esperaVirar = 50;

    
    
};
