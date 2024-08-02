#ifndef TRAJETO_HPP
#define TRAJETO_HPP

#include "../header/tipoTransporte.hpp"
#include "cidade.hpp"

class Trajeto
{
  private:
    Cidade* origem;
    Cidade* destino;
    TipoTransporte tipo;
    float distancia;
  public:
    Trajeto(Cidade* origem, Cidade* destino, TipoTransporte tipo, float distancia);
    Cidade* getOrigem();
    Cidade* getDestino();
    TipoTransporte getTipo();
    float getDistancia();
};

#endif
