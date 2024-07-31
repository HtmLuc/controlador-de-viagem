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
    Tipo tipo;
    int capacidade;
    int velocidade;
    int distancia_entre_descansos;
    int tempo_de_descanso;
    int tempo_de_descanso_atual;
    Cidade* localAtual;
  public:
    Transporte( string nome, Tipo tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, Cidade* localAtual );
    string getNome();
    Tipo getTipo();
    int getCapacidade();
    int getVelocidade();
    int getDistanciaEntreDescansos();
    int getTempoDeDescanso();
    int getTempoDeDescansoAtual();
    Cidade* getLocalAtual();
    
    void setLocalAtual( Cidade* cidade );
};

#endif
