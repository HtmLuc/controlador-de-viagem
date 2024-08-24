#ifndef CONTROLADORDETRANSITO_HPP
#define CONTROLADORDETRANSITO_HPP

#include <string>
#include <list>
#include <vector>
#include "cidade.hpp"
#include "passageiro.hpp"
#include "trajeto.hpp"
#include "transporte.hpp"
#include "viagem.hpp"
#include "dijkstra.hpp"

using namespace std;

class ControladorDeTransito{
  private:
    list<Cidade*>listaCidades;
    list<Trajeto*>listaTrajetos;
    list<Transporte*>listaTransportes;
    list<Passageiro*>listaPassageiros;
    list<Viagem*>listaViagens;
    GrafoCidade grafoCidades;
  public:
    ControladorDeTransito() : grafoCidades({}) {}
    void cadastrarCidade(string nome);
    void cadastrarTrajeto(string nomeOrigem, string nomeDestino, int tipo, float distancia);
    void cadastrarTransporte(string nome, int tipoDeTrajeto, int capacidade, float velocidade, float distanciaDescansos, int tempoDescanso, string localAtual);
    void cadastrarPassageiro(string nome, string localAtual);

    vector<string> calcularMelhorTrajeto(string origem, string destino);

    void iniciarViagem(string nomeTransporte, list<string> nomesPassageiros, string nomeOrigem, string nomeDestino);
    void avancarHoras(int horas);
    void relatarEstado();
    
    // Carregar as informações dos arquivos nas listas
    void carregarCidades();
    void carregarTrajetos();
    void carregarTransportes();
    void carregarPassageiros();
    void carregarViagens();

    bool verificarCidade(string nome);
    bool verificarPassageiro(string nome, string localAtual);
    bool verificarTransporte(string nome, int tipo, int capacidade, float velocidade, float distanciaDescansos, int tempoDescanso, string localAtual);
    bool VerificarTrajeto(string origem, string destino, int tipo, float distancia);
};

#endif
