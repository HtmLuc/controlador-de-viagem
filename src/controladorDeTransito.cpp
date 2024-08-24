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

    // Cadastrar novo passageiro NA LISTA
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
  //Relatar onde está cada pessoa
  cout << "Relatório do local de cada passageiro" << endl;
  for(const auto& passageiro: listaPassageiros){
    if(passageiro->getEmTransito()){
      cout << passageiro->getNome() << " está em trânsito." << endl;
      //acrescentar os outros dados
    }
    else{
      cout << passageiro->getNome() << " está em " << passageiro->getLocalAtual()->getNome() << endl;
    }
  }

  //Relatar onde está cada transporte
  cout << "Relatório do local de cada transporte" << endl;
  for (const auto& transporte : listaTransportes) {
    if (transporte->getEmTransito()) {
      cout << transporte->getNome() << " está em trânsito." << endl;
    }
    else{
      cout << transporte->getNome() << " está em " << transporte->getLocalAtual()->getNome() << endl;
    }
  }

  //Relatar todas as viagens em andamento
  cout << "Relatório de todas as viagens em andamento" << endl;
  for (const auto& viagem : listaViagens) {
        viagem->relatarEstado();
  }

  //Relatar todas as cidade mais visitadas
  cout << "Relatório das cidades mais visitadas" << endl;
  //A se fazer

}

void ControladorDeTransito::IniciarTransporte(string nomeTransporte, string localOrigem, int tipo)
{
  for(auto& transporte : listaTransportes){
    if(transporte->getNome() == nomeTransporte){
      if(transporte->getLocalAtual()->getNome() == localOrigem){
        // verifiacar se é do mesmo tipo;
        cout << "Esse transporte tem capacidade para " << transporte->getCapacidade() << "." << endl;
        cout << "Quantas deseja cadastrar na viagem?" << endl;
        cout << ">>>" << endl;
        int qnt;
        cin >> qnt;
        for(int i = 0; i < qnt; i++)
        {
          cout << "Passageiro " << i+1 << ":";
          string nomePassageiro;
          getline(cin, nomePassageiro);
          while(!verificarNomePassageiro(nomePassageiro))
          {
            cout << "\033[31mERRO: Passageiro não está cadastrado. Tente novamente! \033[0m" << endl;
            cout << "Passageiro " << i+1 << ":";
            getline(cin, nomePassageiro);
          }

          // adicionar passsageiro na lista de passageiros da viagem;
        }

      }
      else{
        cout << "\033[31mERRO: Transporte informado não está cadastrado. Tente novamente! \033[0m" << endl;
        return;
        // retornar que nao está no local de origem da viagem;
      }
    }
  }
}