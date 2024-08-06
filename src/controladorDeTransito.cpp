#include <iostream>
#include <fstream>
#include "../include/controladorDeTransito.hpp"

using namespace std;

void ControladorDeTransito::cadastrarCidade(string nome)
{
  string linha;
  bool cidadeExiste = false;

  // Verifica se a cidade existe no arquivo
  ifstream arquivoLeitura("data/cidade.txt");
  if(arquivoLeitura.is_open())
  {
    while(getline(arquivoLeitura, linha))
    {
      if(linha == nome)
      {
        cout << "\033[31mERRO: Já foi cadastrado uma cidade com esse nome.\033[0m" << endl;
        cidadeExiste = true;
        break;
      }
    }
  }
  arquivoLeitura.close();

  // Escreve o nome da cidade no arquivo
  if(!cidadeExiste)
  {
    ofstream arquivoEscrita("data/cidade.txt", ios::app);
    if(arquivoEscrita.is_open())
    {
      arquivoEscrita.seekp(0, ios::end);
      arquivoEscrita << nome << endl;
      cout << "Cidade cadastrada com sucesso!" << endl;
      arquivoEscrita.close();
    }
    else
    {
      cout << "\033[31mERRO: Não foi possível abir o arquivo para escrita.\033[0m" << endl;
    }
  }
}


void ControladorDeTransito::cadastrarTrajeto(string nomeOrigem, string nomeDestino, TipoTransporte tipo, float distancia)
{
}


void ControladorDeTransito::cadastrarTransporte(string nome, TipoTransporte tipo, int capacidade, float velocidade, float distanciaDescansos, int tempoDescanso, string localAtual)
{
  Cidade* cidadeAtual = nullptr;
  
  carregarCidade("data/cidade.txt");

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
    cout << "\033[31mERRO: Local Atual não existe.\033[0m" << endl;
  }
  else
  {
    ofstream arquivo("data/transporte.txt", ios::app);
    if(arquivo.is_open())
    {
      arquivo.seekp(0, ios::end);
      arquivo << nome << "," << tipo << "," << capacidade << "," << velocidade << "," << distanciaDescansos << "," << tempoDescanso << "," << localAtual << endl;
      cout << "Transporte cadastrado com sucesso!" << endl;
      arquivo.close();
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

void ControladorDeTransito::carregarCidade(string nomeArquivo)
{
  ifstream arquivo(nomeArquivo);
  string linha;
  while(getline(arquivo, linha))
  {
    if(!linha.empty())
    {
      Cidade* cidade = new Cidade(linha);
      listaCidades.push_back(cidade);
    }
  }
}

