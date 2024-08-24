#include "../include/passageiro.hpp"

Passageiro::Passageiro(string nome, Cidade* localAtual, bool emTransito)
{
  this->nome = nome;
  this->localAtual = localAtual;
  this->emTransito = emTransito;
}

string Passageiro::getNome()
{
  return nome;
}

Cidade* Passageiro::getLocalAtual()
{
  return localAtual;
}

void Passageiro::setLocalAtual(Cidade* local)
{
  this->localAtual = local;
}

bool Passageiro::getEmTransito()
{
  return emTransito;
}

void Passageiro::setEmTransito(bool status)
{
  emTransito = status;
}
