#include "../include/controladorDeTransito.hpp"
#include <string>
#include <iostream>

// Retorna verdadeiro caso a cidade exista e falso caso contrário
bool ControladorDeTransito::verificarCidade(string nome){
  string linha;

  // Verifica se a cidade já existe
  for(auto& cidade : listaCidades)
  {
    if(cidade->getNome() == nome)
    {
      return true;
    }
  }
  return false;
}
bool ControladorDeTransito::verificarPassageiro(string nome, string localAtual)
{
  for(auto& passageiro : listaPassageiros)
  {
    if(passageiro->getNome() == nome && passageiro->getLocalAtual()->getNome() == localAtual)
    {
      return true;
    }
  }
  return false;
}
