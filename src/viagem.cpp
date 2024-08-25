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
  for(auto& passageiro : listaPassageiros)
  {
    passageiro->setEmTransito(true);
  }
  this->horasEmTransito = 0;

  cout << "Viagem de " << origem->getNome() << " para " << destino->getNome() << " iniciada com sucesso!" << endl;
}


void Viagem::avancarHoras(int horas)
{
  float distanciaPercorrida = transporte->getVelocidade() * horas;
  distanciaRestante -= distanciaPercorrida;

  tempoDecorrido += horas;

  if(distanciaRestante <= 0)
  {
    transporte->setEmTransito(false);
    for(auto& passageiro : listaPassageiros)
    {
      passageiro->setEmTransito(false);
      passageiro->setLocalAtual(destino);
    }
    transporte->setLocalAtual(destino);
    cout << "Viagem concluída!" << endl;
  }
  else
{
    cout << "Cidade em progresso. Distancia restante: " << distanciaRestante << "km." << endl;
  }
}

void Viagem::relatarEstado()
{
  if(isEmAndamento())
  {
    cout << "Viagem de " << origem->getNome() << " para " << destino->getNome() << " está em andamento." << endl;
    cout << "Distancia restante: " << distanciaRestante << "km." << endl;
    cout << "Tempo decorrido: " << tempoDecorrido << "km." << endl;
  }
  else
{ 
    cout << "Viagem já chegou ao destino: " << destino->getNome() << endl;
  }
}

bool Viagem::isEmAndamento()
{
  return transporte->getEmTransito();
}
