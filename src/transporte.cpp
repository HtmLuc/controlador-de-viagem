#include "../include/transporte.hpp"

Transporte::Transporte(string nome, TipoTransporte tipo, int capacidade, float velocidade, int distanciaDescansos, int tempoDescanso, Cidade* localAtual){
  this->nome = nome;
  this->tipo = tipo;
  this->capacidade = capacidade;
  this->velocidade = velocidade;
  this->distanciaDescansos = distanciaDescansos;
  this->tempoDescanso = tempoDescanso;
  this->localAtual = localAtual;
}

string Transporte::getNome()
{
  return nome;
}

TipoTransporte Transporte::getTipo()
{
  return tipo;
}

int Transporte::getCapacidade()
{
  return capacidade;
}

float Transporte::getVelocidade()
{
  return velocidade;
}

int Transporte::getDistanciaDescansos()
{
  return distanciaDescansos;
}

int Transporte::getTempoDescanso()
{
  return tempoDescanso;
}
int Transporte::getTempoDescansoAtual(){
  return tempoDescansoAtual;
}

Cidade* Transporte::getLocalAtual()
{
  return localAtual;
}

void Transporte::setLocalAtual( Cidade* cidade )
{
  this->localAtual = cidade;
}
