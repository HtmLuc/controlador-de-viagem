#include "../include/transporte.hpp"

Transporte::Transporte(string nome, int tipo, int capacidade, float velocidade, int distanciaDescansos, int tempoDescanso, Cidade* localAtual, bool emTransito){
  this->nome = nome;
  this->tipo = tipo;
  this->capacidade = capacidade;
  this->velocidade = velocidade;
  this->distanciaDescansos = distanciaDescansos;
  this->tempoDescanso = tempoDescanso;
  this->localAtual = localAtual;
  this->emTransito = emTransito;
}

string Transporte::getNome()
{
  return nome;
}

int Transporte::getTipo()
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

bool Transporte::getEmTransito()
{
  return emTransito;
}

void Transporte::setEmTransito(bool status)
{
  this->emTransito = status;
}
