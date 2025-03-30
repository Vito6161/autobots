#include "lerRefletancia.h"

void lerRefletancia::atualizarValoresRef()
{
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
  valorSensorEsq = robo.lerSensorLinhaEsq(); 
  valorSensorDir = robo.lerSensorLinhaDir(); 
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
}

bool lerRefletancia::Esquerda(){return (pppb() || ppbb() || pbbb() || bpbb());}
bool lerRefletancia::Direita(){return (bppp() || bbpp() || bbbp() || bbpb());}
bool lerRefletancia::Frente(){return (bbbb() || bppb() || pppp() || pbpb() || bpbp() || pbbp());}
bool lerRefletancia::Re(){return (pbbp());}
bool lerRefletancia::Parar(){return (!Esquerda() && !Direita() && !Frente() && !Re());}

