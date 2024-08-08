#include <iostream>
#include <fstream>
#include "../include/controladorDeTransito.hpp"

using namespace std;

void ControladorDeTransito::cadastrarCidade(string nome)
{
  string linha;

  // Cadastrar a nova cidade NO ARQUIVO
  ofstream arquivo("data/cidade.txt", ios::app);
  if(arquivo.is_open())
  {
    arquivo.seekp(0, ios::end);
    arquivo << nome << endl;
    cout << "Cidade cadastrada com sucesso!" << endl;
    arquivo.close();
  }
  else
  {
    cout << "\033[31mERRO: Não foi possível abir o arquivo para escrita.\033[0m" << endl;
  }

  // Cadastrar a nova cidade NA LISTA
  Cidade* novaCidade = new Cidade(nome);
  listaCidades.push_back(novaCidade);
}


void ControladorDeTransito::cadastrarTrajeto(string nomeOrigem, string nomeDestino, TipoTransporte tipo, float distancia)
{
  string linha;
  // VERIFICAR SE JÁ EXISTE O TRAJETO
  ofstream arquivo("data/trajeto.txt", ios::app);
  if(arquivo.is_open())
  {
    arquivo.seekp(0, ios::end);
    arquivo << nomeOrigem << "," << nomeDestino << "," << tipo << "," << distancia << endl;
    cout << "Trajeto cadastrado com sucesso!" << endl;
    arquivo.close();
  }

  Cidade* novaCidadeOrigem = new Cidade(nomeOrigem);
  Cidade* novaCidadeDestino = new Cidade(nomeDestino);
  Trajeto* novoTrajeto = new Trajeto(novaCidadeOrigem, novaCidadeDestino, tipo, distancia);
  listaTrajetos.push_back(novoTrajeto);
}

void ControladorDeTransito::cadastrarTransporte(string nome, TipoTransporte tipo, int capacidade, float velocidade, float distanciaDescansos, int tempoDescanso, string localAtual)
{
  // VERIFICAR SE O TRANSPORTE EXISTE

  ofstream arquivo("data/transporte.txt", ios::app);
  if(arquivo.is_open())
  {
    int tipoInt;
    if(tipo == 0)
    {
      tipoInt = 0;
    }
    else{
      tipoInt = 1;
    }
    arquivo.seekp(0, ios::end);
    arquivo << nome << "," << tipo << "," << capacidade << "," << velocidade << "," << distanciaDescansos << "," << tempoDescanso << "," << localAtual << endl;
    cout << "Transporte cadastrado com sucesso!" << endl;
    arquivo.close();

    // Cadastrar novo transporte NA LISTA
    Cidade* cidadeAtual = new Cidade(localAtual);
    Transporte* novaCidade = new Transporte(nome, tipo, capacidade, velocidade, distanciaDescansos, tempoDescanso, cidadeAtual);
    listaTransportes.push_back(novaCidade);
  }
  else
  {
    cout << "\033[31mERRO: Não foi possível abrir o arquivo para escrita." << endl;
  }
}

void ControladorDeTransito::cadastrarPassageiro(string nome, string localAtual)
{
  // Cadastrar novo passageiro NO ARQUIVO
  ofstream arquivo("data/passageiro.txt", ios::app);
  if(arquivo.is_open())
  {
    arquivo.seekp(0, ios::end);
    arquivo << nome << "," << localAtual << endl;
    cout << "Passageiro cadastrado com sucesso!" << endl;
    arquivo.close();

    // Cadasstrar novo passageiro NA LISTA
    Cidade* cidadeAtual = new Cidade(localAtual);
    Passageiro* novoPassageiro = new Passageiro(nome, cidadeAtual);
    listaPassageiros.push_back(novoPassageiro);
  }
  else
{
    cout << "\033[31mERRO: Não foi possível abrir o arquivo para escrita." << endl;
  }
}

void ControladorDeTransito::iniciarViagem(string nomeTransporte, list<string> nomesPassageiros, string nomeOrigem, string nomeDestino)
{
}

void ControladorDeTransito::avancarHoras(int horas)
{
}

void ControladorDeTransito::relatarEstado()
{
}
