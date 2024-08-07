#include <iostream>
#include <fstream>
#include "../include/controladorDeTransito.hpp"

void ControladorDeTransito::carregarCidades(string nomeArquivo)
{
  ifstream arquivo(nomeArquivo);
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

void ControladorDeTransito::carregarTrajetos(string nomeArquivo)
{
  ifstream arquivo(nomeArquivo);
  string linha;
  if(arquivo.is_open())
  {
    while(getline(arquivo, linha))
    {
      if(!linha.empty())
      {
        //Trajeto* trajetoArquivo = new Trajeto(linha);
      }
    }
  }
 }

void ControladorDeTransito::carregarTransportes(string nomeArquivo)
{
}

void ControladorDeTransito::carregarPassageiro(string nomeArquivo)
{
}

void ControladorDeTransito::carregarViagens(string nomeArquivo)
{
}