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
/*
void ControladorDeTransito::cadastrarTrajeto(string nomeOrigem, string nomeDestino, TipoTransporte tipo, float distancia)
{
}

void ControladorDeTransito::cadastrarTransporte(string nome, TipoTransporte tipo, int capacidade, float velocidade, float distanciaDescansos, int tempoDescanso, string localAtual)
{
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
*/
/**/