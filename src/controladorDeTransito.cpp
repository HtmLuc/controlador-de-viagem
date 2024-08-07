#include <iostream>
#include <fstream>
#include "../include/controladorDeTransito.hpp"

using namespace std;

void ControladorDeTransito::cadastrarCidade(string nome)
{
  string linha;
  bool cidadeExiste = false;

  // Verifica se a cidade já existe
  for(auto& cidade : listaCidades)
  {
    if(cidade->getNome() == nome)
    {
      cout << "\033[31mERRO: Cidade informada já está cadastrada. Tente novamente.\033[0m" << endl;
      cidadeExiste = true;
      break;
    }
  }

  if(!cidadeExiste)
  {
    // Cadastrar a nova cidade NO ARQUIVO
    ofstream arquivo("data/cidade.txt", ios::app);
    if(arquivo.is_open())
    {
      arquivo.seekp(0, ios::end);
      arquivo << nome << endl;
      cout << "Cidade cadastrada com sucesso!" << endl;
      arquivo.close();
      //incrementando nova cidade na lista;
      Cidade* cidade = new Cidade(nome);
      listaCidades.push_back(cidade);
    }
    else
    {
      cout << "\033[31mERRO: Não foi possível abir o arquivo para escrita.\033[0m" << endl;
    }

    // Cadastrar a nova cidade NA LISTA
    Cidade* novaCidade = new Cidade(nome);
    listaCidades.push_back(novaCidade);
  }
}


void ControladorDeTransito::cadastrarTrajeto(string nomeOrigem, string nomeDestino, TipoTransporte tipo, float distancia)
{
}

void ControladorDeTransito::cadastrarTransporte(string nome, TipoTransporte tipo, int capacidade, float velocidade, float distanciaDescansos, int tempoDescanso, string localAtual)
{
  Cidade* cidadeAtual = nullptr;
  
  // Verificar se o localAtual já foi cadastrado nos arquivos
  for(auto& cidade : listaCidades)
  {
    if(cidade->getNome() == localAtual)
    {
      cidadeAtual = cidade;
      break;
    }
  }

  if(cidadeAtual == nullptr)
  {
    cout << "\033[31mERRO: Local Atual não existe. Tente novamente!\033[0m" << endl;
  }
  else
  {
    // Cadastrar novo transporte NO ARQUIVO
    ofstream arquivo("data/transporte.txt", ios::app);
    if(arquivo.is_open())
    {
      arquivo.seekp(0, ios::end);
      arquivo << nome << "," << tipo << "," << capacidade << "," << velocidade << "," << distanciaDescansos << "," << tempoDescanso << "," << localAtual << endl;
      cout << "Transporte cadastrado com sucesso!" << endl;
      arquivo.close();

      // Cadastrar novo transporte NA LISTA
      Transporte* novaCidade = new Transporte(nome, tipo, capacidade, velocidade, distanciaDescansos, tempoDescanso, cidadeAtual);
      listaTransportes.push_back(novaCidade);
    }
    else
    {
      cout << "\033[31mERRO: Não foi possível abrir o arquivo para escrita." << endl;
    }
  }
}

void ControladorDeTransito::cadastrarPassageiro(string nome, string localAtual)
{
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
