#include "../class/viagem.hpp"

Viagem::Viagem( Transporte* transporte, list<Passageiro*>passageiros, Cidade* origem, Cidade* destino )
{
  this->transporte = transporte;
  this->passageiros = passageiros;
  this->origem = origem;
  this->destino = destino;
}

void Viagem::iniciarViagem()
{
  //TO-DO
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
  //TO-DO;
}
