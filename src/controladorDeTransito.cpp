#include <iostream>
#include <fstream>
#include <limits>
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
  Cidade* cidadeOrigem = nullptr;
  Cidade* cidadeDestino = nullptr;

  for (auto& cidade : listaCidades)
  {
    if (cidade->getNome() == nomeOrigem)
    {
      cidadeOrigem = cidade;
    }
    else if (cidade->getNome() == nomeDestino)
    {
      cidadeDestino = cidade;
    }
  }

  if (cidadeOrigem == nullptr || cidadeDestino == nullptr)
  {
    cout << "\033[31mERRO: Cidade de origem ou destino não encontrada.\033[0m" << endl;
    return;
  }

  Transporte* transporteEscolhido = nullptr;
  for (auto& transporte : listaTransportes)
  {
    if (transporte->getNome() == nomeTransporte)
    {
      transporteEscolhido = transporte;
      break;
    }
  }

  if (transporteEscolhido == nullptr)
  {
    cout << "\033[31mERRO: Transporte não encontrado.\033[0m" << endl;
    return;
  }

  if (transporteEscolhido->getLocalAtual()->getNome() != nomeOrigem)
  {
    cout << "\033[31mERRO: O transporte não está na cidade de origem.\033[0m" << endl;
    return;
  }

  cout << "Digite os nomes dos passageiros (Digite 0 para terminar):" << endl;
  string nome;
  list<Passageiro*> passageirosNaOrigem;
  while (true)
  {
    getline(cin, nome);
    if (nome == "0")
    {
      break;
    }

    bool passageiroEncontrado = false;
    for (auto& passageiro : listaPassageiros)
    {
      if (passageiro->getNome() == nome && passageiro->getLocalAtual()->getNome() == nomeOrigem)
      {
        passageirosNaOrigem.push_back(passageiro);
        passageiroEncontrado = true;
        break;
      }
    }

    if (!passageiroEncontrado)
    {
      cout << "\033[31mERRO: Passageiro " << nome << " não encontrado na cidade de origem.\033[0m" << endl;
    }
  }

  // Salvar a viagem no arquivo (essa parte precisará ser ajustada para serializar corretamente os dados)
  ofstream arquivo("data/viagem.txt", ios::app);
  if (arquivo.is_open())
  {
    // Exemplo de salvamento básico - você deve decidir como serializar adequadamente os dados
    arquivo << nomeTransporte << "," << nomeOrigem << "," << nomeDestino << "," << passageirosNaOrigem.size() << " passageiros" << endl;
    arquivo.close();
  }
  else
{
    cout << "\033[31mERRO: Não foi possível abrir o arquivo para escrita.\033[0m" << endl;
  }

  Viagem* novaViagem = new Viagem(transporteEscolhido, passageirosNaOrigem, cidadeOrigem, cidadeDestino);
  novaViagem->iniciarViagem();
  listaViagens.push_back(novaViagem);
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
