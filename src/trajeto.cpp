#include "../include/trajeto.hpp"

Trajeto::Trajeto(Cidade* origem, Cidade* destino, int tipo, float distancia)
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

int Trajeto::getTipo()
{
  return tipo;
}

float Trajeto::getDistancia()
{
  return distancia;
}
