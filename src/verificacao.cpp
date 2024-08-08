#include "../include/controladorDeTransito.hpp"
#include "../include/tipoTransporte.hpp"
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

TipoTransporte pedirTipo(int entrada)
{
  if(entrada == 0)
  {
    return TipoTransporte::AQUATICO;
  }
  else if(entrada == 1)
  {
    return TipoTransporte::TERRESTRE;
  }
  else
  {
    cout << "AVISO: Não foi informado um tipo de transporte válido, por padrão o tipo é TERRESTRE." << endl;
    return TipoTransporte::TERRESTRE;
  }
}