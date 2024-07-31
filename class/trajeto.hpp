#ifndef TRAJETO_HPP
#define TRAJETO_HPP

#include "../header/tipoTransporte.hpp"
#include "cidade.hpp"

class Trajeto
{
  private:
    Cidade* origem;
    Cidade* destino;
    Tipo tipo;
    int distancia;
  public:
    Trajeto( Cidade* origem, Cidade* destino, Tipo tipo, int distancia );
    Cidade* getOrigem();
    Cidade* getDestino();
    Tipo getTipo();
    int getDistancia();
};

#endif
