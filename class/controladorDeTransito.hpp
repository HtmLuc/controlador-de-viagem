#ifndef CONTROLADORDETRANSITO_HPP
#define CONTROLADORDETRANSITO_HPP

#include <string>
#include <list>
#include "../header/tipoTransporte.hpp"
#include "cidade.hpp"
#include "passageiro.hpp"
#include "trajeto.hpp"
#include "transporte.hpp"
#include "viagem.hpp"

using std::list, std::string;

class ControladorDeTransito{
  private:
    list<Cidade*>cidades;
    list<Trajeto*>trajetos;
    list<Transporte*>transportes;
    list<Passageiro*>passageiros;
    list<Viagem*>viagens;
  public:
    void cadastrarCidade(string nome);
    void cadastrarTrajeto(string nomeOrigem, string nomeDestino, TipoTransporte tipo, float distancia);
    void cadastrarTransporte(string nome, TipoTransporte tipo, int capacidade, float velocidade, float distanciaDescansos, int tempoDescanso, string localAtual);
    void cadastrarPassageiro(string nome, string localAtual);

    void iniciarViagem(string nomeTransporte, list<string> nomesPassageiros, string nomeOrigem, string nomeDestino);
    void avancarHoras(int horas);
    void relatarEstado();
};

#endif
