#ifndef lerRefletancia_H
#define lerRefletancia_H


#include <robo_hardware2.h>

class lerRefletancia
{

  public:
    
    bool Esquerda();
    bool Direita();
    bool Frente();
    bool Re();
    bool Parar();

    void atualizarValoresRef();

  private:
    
    float valorSensorMaisEsq;
    float valorSensorEsq; 
    float valorSensorDir;
    float valorSensorMaisDir;

    #define DIVISOR_BRANCO_PRETO 90

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

};

#endif