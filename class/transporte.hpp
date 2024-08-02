#ifndef TRANSPORTE_HPP
#define TRANSPORTE_HPP

#include <string>
#include "../header/tipoTransporte.hpp"
#include "cidade.hpp"

using std::string;

class Transporte
{
  private:
    string nome;
    TipoTransporte tipo;
    int capacidade;
    float velocidade;
    int distanciaDescansos;
    int tempoDescanso;
    int tempoDescansoAtual;
    Cidade* localAtual;
  public:
    Transporte(string nome, TipoTransporte tipo, int capacidade, float velocidade, int distanciaDescansos, int tempoDescanso, Cidade* localAtual);
    string getNome();
    TipoTransporte getTipo();
    int getCapacidade();
    float getVelocidade();
    int getDistanciaDescansos();
    int getTempoDescanso();
    int getTempoDescansoAtual();
    Cidade* getLocalAtual();
    
    void setLocalAtual(Cidade* cidade);
};

#endif
