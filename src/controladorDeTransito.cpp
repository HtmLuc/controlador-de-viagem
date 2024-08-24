#include <iostream>
#include <fstream>
#include "../include/controladorDeTransito.hpp"

using namespace std;

void ControladorDeTransito::cadastrarCidade(string nome)
{
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


void ControladorDeTransito::cadastrarTrajeto(string nomeOrigem, string nomeDestino, int tipo, float distancia)
{
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

  grafoCidades.adicionarTrajeto(nomeOrigem, nomeDestino, distancia);
}

void ControladorDeTransito::cadastrarTransporte(string nome, int tipo, int capacidade, float velocidade, float distanciaDescansos, int tempoDescanso, string localAtual)
{
  
  ofstream arquivo("data/transporte.txt", ios::app);
  if(arquivo.is_open())
  {
    arquivo.seekp(0, ios::end);
    arquivo << nome << "," << tipo << "," << capacidade << "," << velocidade << "," << distanciaDescansos << "," << tempoDescanso << "," << localAtual << ",false" << endl;
    cout << "Transporte cadastrado com sucesso!" << endl;
    arquivo.close();

    // Cadastrar novo transporte NA LISTA
    Cidade* cidadeAtual = new Cidade(localAtual);
    Transporte* novaCidade = new Transporte(nome, tipo, capacidade, velocidade, distanciaDescansos, tempoDescanso, cidadeAtual, false);
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
    arquivo << nome << "," << localAtual << ",false" << endl;
    cout << "Passageiro cadastrado com sucesso!" << endl;
    arquivo.close();

    // Cadasstrar novo passageiro NA LISTA
    Cidade* cidadeAtual = new Cidade(localAtual);
    Passageiro* novoPassageiro = new Passageiro(nome, cidadeAtual, false);
    listaPassageiros.push_back(novoPassageiro);
  }
  else
{
    cout << "\033[31mERRO: Não foi possível abrir o arquivo para escrita." << endl;
  }
}

vector<string> ControladorDeTransito::calcularMelhorTrajeto(string origem, string destino) {
  return grafoCidades.caminhoCurto(origem, destino);
}

void ControladorDeTransito::iniciarViagem(string nomeTransporte, string nomeOrigem, string nomeDestino)
{
  vector<string> melhorCaminho = calcularMelhorTrajeto(nomeOrigem, nomeDestino);

  if (melhorCaminho.empty()) 
  { 
    cout << "\033[31mERRO: Não foi encontrado um trajeto entre as cidades informadas.\033[0m" << endl;
    return;
  }

  cout << "Melhor trajeto de " << nomeOrigem << " para " << nomeDestino << ":" << endl;
  for (auto& cidade : melhorCaminho)
  {
    cout << cidade << " -> ";
  }
  cout << "CHEGADA" << endl;
}

void ControladorDeTransito::avancarHoras(int horas)
{
  for(auto& viagem : listaViagens)
  {
    viagem->avancarHoras(horas);
  }

}

void ControladorDeTransito::relatarEstado()
{
}
