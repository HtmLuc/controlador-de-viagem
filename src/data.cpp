#include <iostream>
#include <fstream>
#include "../include/controladorDeTransito.hpp"

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

void ControladorDeTransito::carregarTrajetos()
{
  ifstream arquivo("data/trajeto.txt");
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

void ControladorDeTransito::carregarTransportes()
{
}

void ControladorDeTransito::carregarPassageiro()
{
}

void ControladorDeTransito::carregarViagens()
{
}