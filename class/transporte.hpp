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
    float distancia_entre_descansos;
    int tempo_de_descanso;
    int tempo_de_descanso_atual;
    Cidade* localAtual;
  public:
    Transporte( string nome, TipoTransporte tipo, int capacidade, float velocidade, float distancia_entre_descansos, int tempo_de_descanso, Cidade* localAtual );
    string getNome();
    TipoTransporte getTipo();
    int getCapacidade();
    float getVelocidade();
    float getDistanciaEntreDescansos();
    int getTempoDeDescanso();
    int getTempoDeDescansoAtual();
    Cidade* getLocalAtual();
    
    void setLocalAtual( Cidade* cidade );
};

#endif
