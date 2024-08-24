#ifndef VIAGEM_HPP
#define VIAGEM_HPP

#include <list>
#include "transporte.hpp"
#include "passageiro.hpp"

using namespace std; 

class Viagem
{
private:
  Transporte* transporte;
  list<Passageiro*> listaPassageiros;
  Cidade* origem;
  Cidade* destino;
  Viagem* proxima;
  int horasEmTransito;
  float distanciaRestante;
  int tempoDecorrido;
  bool emAndamento;
public:
  Viagem(Transporte* transporte, list<Passageiro*>passageiros, Cidade* origem, Cidade* destino);
  void iniciarViagem();
  void avancarHoras(int horas);
  void relatarEstado();
  bool isEmAndamento();
};

#endif
