#include "../include/trajeto.hpp"

Trajeto::Trajeto(Cidade* origem, Cidade* destino, TipoTransporte tipo, float distancia)
{
  this->origem = origem;
  this->destino = destino;
  this->tipo = tipo;
  this->distancia = distancia;
}

Cidade* Trajeto::getOrigem()
{
  return origem;
}

Cidade* Trajeto::getDestino()
{
  return destino;
}

TipoTransporte Trajeto::getTipo()
{
  return tipo;
}

float Trajeto::getDistancia()
{
  return distancia;
}
