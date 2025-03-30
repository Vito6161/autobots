#include <robo_hardware2.h>

class Desvio
{
  public:
    
    void DesviarEsquerda();
    void DesviarDireita();

  private: 
    
    #define DistanciaSensor 4
    #define espera 780 
    #define esperaFrente 870  

    void atualizarValorSonar();

    float valorSonar;
};