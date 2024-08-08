#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/controladorDeTransito.hpp"
#include "../include/tipoTransporte.hpp"


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
  ifstream arquivo("data/trajeto.txt");
  string linha;
  if(arquivo.is_open())
  {
    while(getline(arquivo, linha))
    {
      if(!linha.empty())
      {
        stringstream xx(linha);
        string nome, localAtualS;
        TipoTransporte tipoEnum;
        int tipo, capacidade, distanciaDescansos, tempoDescanso;
        float velocidade;
        Cidade* localAtual;

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

        tipoEnum = pedirTipo(tipo);
        localAtual = new Cidade(localAtualS);

        Transporte* trajetoArquivo = new Transporte(nome, tipoEnum, capacidade, velocidade, distanciaDescansos, tempoDescanso, localAtual);

        listaTransportes.push_back(trajetoArquivo);
      }
    }
  }
 }

//void ControladorDeTransito::carregarTransportes()
//{
//}

void ControladorDeTransito::carregarPassageiro()
{
}

void ControladorDeTransito::carregarViagens()
{
}