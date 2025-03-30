#include "lerRefletancia.h"

void lerRefletancia::atualizarValoresRef()
{
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
  valorSensorEsq = robo.lerSensorLinhaEsq(); //Le o valor do sensor esquerdo e coloca dentro da variavel valor_sensor_esq
  valorSensorDir = robo.lerSensorLinhaDir(); //Le o valor do sensor direito e coloca dentro da variavel valor_sensor_dir
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
}

inline bool lerRefletancia::Esquerda(){return (pppb() || ppbb() || pbbb() || bpbb());}
inline bool lerRefletancia::Direita(){return (bppp() || bbpp() || bbbp() || bbpb());}
inline bool lerRefletancia::Frente(){return (bbbb() || bppb() || pppp() || pbpb() || bpbp() || pbbp());}
inline bool lerRefletancia::Re(){return (pbbp());}
inline bool lerRefletancia::Parar(){return (!Esquerda() && !Direita() && !Frente() && !Re());}

