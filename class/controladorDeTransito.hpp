#ifndef CONTROLADORDETRANSITO_HPP
#define CONTROLADORDETRANSITO_HPP

#include <string>
#include <vector>
#include "../header/tipoTransporte.hpp"
#include "cidade.hpp"
#include "passageiro.hpp"
#include "trajeto.hpp"
#include "transporte.hpp"
#include "viagem.hpp"

using std::vector, std::string;

class ControladorDeTransito{
  private:
    vector<Cidade*>cidades;
    vector<Trajeto*>trajetos;
    vector<Transporte*>transportes;
    vector<Passageiro*>passageiros;
    vector<Viagem*>viagens;
  public:
    void cadastrarCidade( string nome );
    void cadastrarTrajeto( string nomeOrigem, string nomeDestino, Tipo tipo, int distancia );
    void cadastrarTransporte( string nome, Tipo tipo, int capacidade, int velocidade, int distancia_entredescansos, int tempo_de_descanso, string localAtual );
    void cadastrarPassageiro( string nome, string localAtual );
    void iniciarViagem( string nomeTransporte, vector<string> nomesPassageiros, string nomeOrigem, string nomeDestino );
    void avancarHoras( int horas );
    void relatarEstado();
};

#endif
