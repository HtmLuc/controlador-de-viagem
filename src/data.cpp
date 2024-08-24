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
        string nome, localAtualS;
        int tipo, capacidade, distanciaDescansos, tempoDescanso;
        float velocidade;
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
        getline(xx, localAtualS);
        localAtual = new Cidade(localAtualS);
        
        Transporte* trajetoArquivo = new Transporte(nome, tipo, capacidade, velocidade, distanciaDescansos, tempoDescanso, localAtual);

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
      string nome, localAtualS;
      
      getline(xx, nome, ',');
      getline(xx, localAtualS, ',');

      Cidade* localAtual = nullptr;
      localAtual = new Cidade(localAtualS);

      Passageiro* PassageiroArquivo = new Passageiro(nome, localAtual);

      listaPassageiros.push_back(PassageiroArquivo);
    }
  }
}

void ControladorDeTransito::carregarTrajetos()
{
  ifstream arquivo("data/trajeto.txt");
  string linha;
  if(arquivo.is_open())
  {
    while(getline(arquivo, linha)){
      istringstream xx(linha);
      string origemS, destinoS;
      int tipo;
      float distancia;

      getline(xx, origemS, ',');
      getline(xx, destinoS, ',');
      xx >> tipo;
      xx.ignore();
      xx >> distancia;

      Cidade* destino = new Cidade(origemS);
      Cidade* origem = new Cidade(destinoS);

      Trajeto* TrajetoArquivo = new Trajeto(origem, destino, tipo, distancia);

      listaTrajetos.push_back(TrajetoArquivo);
    }
  }
}
