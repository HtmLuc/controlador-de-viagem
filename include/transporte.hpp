#ifndef TRANSPORTE_HPP
#define TRANSPORTE_HPP

#include <string>
#include "cidade.hpp"

using namespace std;

class Transporte
{
  private:
    string nome;
    int tipo;
    int capacidade;
    float velocidade;
    int distanciaDescansos;
    int tempoDescanso;
    int tempoDescansoAtual;
    Cidade* localAtual;
    bool emTransito;
  public:
    Transporte(string nome, int tipo, int capacidade, float velocidade, int distanciaDescansos, int tempoDescanso, Cidade* localAtual);
    string getNome();
    int getTipo();
    int getCapacidade();
    float getVelocidade();
    int getDistanciaDescansos();
    int getTempoDescanso();
    int getTempoDescansoAtual();
    Cidade* getLocalAtual();
    
    void setLocalAtual(Cidade* cidade);

    bool getEmTransito();
    void setEmTransito(bool status);
};

#endif
