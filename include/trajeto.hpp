#ifndef TRAJETO_HPP
#define TRAJETO_HPP

#include "cidade.hpp"

class Trajeto
{
  private:
    Cidade* origem;
    Cidade* destino;
    int tipo;
    float distancia;
  public:
    Trajeto(Cidade* origem, Cidade* destino, int tipo, float distancia);
    Cidade* getOrigem();
    Cidade* getDestino();
    int getTipo();
    float getDistancia();
};

#endif
