#ifndef VIAGEM_HPP
#define VIAGEM_HPP

#include <list>
#include "transporte.hpp"
#include "trajeto.hpp"
#include "passageiro.hpp"

using std::list;

class Viagem
{
private:
  Transporte* transporte;
  list<Passageiro*> passageiros;
  Cidade* origem;
  Cidade* destino;
  Viagem* proxima;
  int HorasEmTransito;
  bool emAndamento;
public:
  Viagem(Transporte* transporte, list<Passageiro*>passageiros, Cidade* origem, Cidade* destino);
  void iniciarViagem();
  void avancarHoras(int horas);
  void relatarEstado();
  bool isEmAndamento();
};

#endif
