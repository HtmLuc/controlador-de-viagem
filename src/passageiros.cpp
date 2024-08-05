#include "../include/passageiro.hpp"

Passageiro::Passageiro(string nome, Cidade* localAtual)
{
  this->nome = nome;
  this->localAtual = localAtual;
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
