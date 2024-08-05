#include "../include/cidade.hpp"

Cidade::Cidade(string nome)
{
  this->nome = nome;
}

string Cidade::getNome()
{
  return nome;
}
