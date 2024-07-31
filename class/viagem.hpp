#ifndef VIAGEM_HPP
#define VIAGEM_HPP

#include <vector>
#include "transporte.hpp"
#include "trajeto.hpp"
#include "passageiro.hpp"

using std::vector;

class Viagem
{
private:
  Transporte* transporte;
  vector<Passageiro*> passageiros;
  Cidade* origem;
  Cidade* destino;
  Viagem* proxima;
  int HorasEmTransito;
  bool emAndamento;
public:
  Viagem( Transporte* transporte, vector<Passageiro*>passageiros, Cidade* origem, Cidade* destino );
  void iniciarViagem();
  void avancarHoras( int horas );
  void relatarEstado();
  bool isEmAndamento();
};

#endif
