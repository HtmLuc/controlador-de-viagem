#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/controladorDeTransito.hpp"


using namespace std;

void ControladorDeTransito::carregarCidades()
{
  ifstream arquivo("data/cidade.txt");
  string linha;
  if(arquivo.is_open())
  {
    while(getline(arquivo, linha))
    {
      if(!linha.empty())
      {
        Cidade* novaCidade = new Cidade(linha);
        listaCidades.push_back(novaCidade);
      }
    }
  }
}

void ControladorDeTransito::carregarTransportes()
{
  ifstream arquivo("data/transporte.txt");
  string linha;
  if(arquivo.is_open())
  {
    while(getline(arquivo, linha))
    {
      istringstream xx(linha);
      string nome, localAtualS, entrada;
      int tipo, capacidade, distanciaDescansos, tempoDescanso;
      float velocidade;
      bool emTransito;

      Cidade* localAtual = nullptr;

      getline(xx, nome, ',');
      xx >> tipo;
      xx.ignore();
      xx >> capacidade;
      xx.ignore();
      xx >> velocidade;
      xx.ignore();
      xx >> distanciaDescansos;
      xx.ignore();
      xx >> tempoDescanso;
      xx.ignore();
      getline(xx, localAtualS, ',');
      getline(xx, entrada);
      if(entrada == "false")
      {
        emTransito = false;
      }
      else if(entrada == "true")
      {
        emTransito = true;
      }

      localAtual = new Cidade(localAtualS);

      Transporte* trajetoArquivo = new Transporte(nome, tipo, capacidade, velocidade, distanciaDescansos, tempoDescanso, localAtual, emTransito);

      listaTransportes.push_back(trajetoArquivo);
    }
  }
}

void ControladorDeTransito::carregarPassageiros()
{
  ifstream arquivo("data/passageiro.txt");
  string linha;
  if(arquivo.is_open())
  {
    while(getline(arquivo, linha)){
      istringstream xx(linha);
      string nome, localAtualS, entrada;
      bool emTransito;

      getline(xx, nome, ',');
      getline(xx, localAtualS, ',');
      getline(xx, entrada);
      if(entrada == "false")
      {
        emTransito = false;
      }
      else if(entrada == "true")
      {
        emTransito = true;
      }
      Cidade* localAtual = new Cidade(localAtualS);

      Passageiro* passageiroArquivo = new Passageiro(nome, localAtual, emTransito);

      listaPassageiros.push_back(passageiroArquivo);
    }
  }
}

void ControladorDeTransito::carregarTrajetos()
{
  ifstream arquivo("data/viagem.txt");
  string linha;

  if (arquivo.is_open()) {
    while (getline(arquivo, linha)) {
      istringstream ss(linha);
      string nomeTransporte, nomeOrigem, nomeDestino, nomePassageiro;
      list<Passageiro*> passageiros;

      getline(ss, nomeTransporte, ',');
      getline(ss, nomeOrigem, ',');
      getline(ss, nomeDestino, ',');

      // Criar ponteiros para a origem e destino
      Cidade* origem = nullptr;
      Cidade* destino = nullptr;
      Transporte* transporte = nullptr;

      // Encontrar as cidades na lista de cidades
      for (auto& cidade : listaCidades) {
        if (cidade->getNome() == nomeOrigem) {
          origem = cidade;
        } else if (cidade->getNome() == nomeDestino) {
          destino = cidade;
        }
      }

      // Encontrar o transporte na lista de transportes
      for (auto& t : listaTransportes) {
        if (t->getNome() == nomeTransporte) {
          transporte = t;
          break;
        }
      }

      // Carregar passageiros
      while (getline(ss, nomePassageiro, ',')) {
        for (auto& passageiro : listaPassageiros) {
          if (passageiro->getNome() == nomePassageiro && passageiro->getLocalAtual()->getNome() == nomeOrigem) {
            passageiros.push_back(passageiro);
            break;
          }
        }
      }

      // Criar uma nova viagem e adicioná-la à lista de viagens
      if (origem && destino && transporte) {
        Viagem* viagem = new Viagem(transporte, passageiros, origem, destino);
        listaViagens.push_back(viagem);
      }
    }
    arquivo.close();
  }
}
