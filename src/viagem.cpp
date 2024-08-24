#include <cstdlib>
#include <iostream>
#include "../include/viagem.hpp"

using namespace std;

Viagem::Viagem( Transporte* transporte, list<Passageiro*>passageiros, Cidade* origem, Cidade* destino )
{
  this->transporte = transporte;
  this->listaPassageiros = passageiros;
  this->origem = origem;
  this->destino = destino;
}

void Viagem::iniciarViagem()
{
  if(transporte->getLocalAtual()->getNome() != origem->getNome())
  {
    cout << "\033[31mERRO: O transporte não está na cidade de origem.\033[0m" << endl;
    return;
  }
  transporte->setEmTransito(true);
  for(auto passageiro : listaPassageiros)
  {
    passageiro->setEmTransito(true);
  }
  this->horasEmTransito = 0;

  cout << "Viagem de " << origem->getNome() << " para " << destino->getNome() << " iniciada com sucesso!" << endl;
}


void Viagem::avancarHoras(int horas)
{
  //TO-DO;
}

void Viagem::relatarEstado()
{
  //TO-DO;
}

bool Viagem::isEmAndamento()
{
  return transporte->getEmTransito();
}
