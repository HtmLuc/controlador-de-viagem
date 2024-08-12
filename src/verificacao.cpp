#include <string>
#include <iostream>
#include "../include/controladorDeTransito.hpp"

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

bool ControladorDeTransito::verificarTransporte(string nomeTransporte, int tipo, int capacidade, float velocidade, float distanciaDescansos, int tempoDescanso, string localAtual)
{
  for(auto& transporte : listaTransportes)
  {
    if(transporte->getNome() == nomeTransporte && transporte->getTipo() == tipo && transporte->getCapacidade() == capacidade && transporte->getVelocidade() == velocidade && transporte->getDistanciaDescansos() == distanciaDescansos && transporte->getTempoDescanso() == tempoDescanso && transporte->getLocalAtual()->getNome() == localAtual)
    {
      return true;
    }
  }
  return false;
}
