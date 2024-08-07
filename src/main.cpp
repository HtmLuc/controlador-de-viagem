#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include "../include/controladorDeTransito.hpp"
#include "../include/tipoTransporte.hpp"

using namespace std;

void menu(int&);

void limparTela();

TipoTransporte pedirTipoTransporte(int);

int main()
{
  ControladorDeTransito controle;
  int opcao;
  string nomeCidade, nomeTransporte, localAtual, nomePassageiro;
  TipoTransporte tipo;
  int capacidade, tempoDescanso, entrada;
  float velocidade, distanciaDescanso;
  
  cout << "┌─────────────────────────────────────────────────┐" << endl;
  cout << "│Bem-vindo ao sistema de gerenciamento de viagens!│" << endl;
  cout << "└─────────────────────────────────────────────────┘" << endl << endl;
  
  // Puxando informações dos arquivos
  controle.carregarCidades();

  do
  {
    menu(opcao);
    
    switch(opcao)
    {
      case 0:
        cout << "Até a próxima!" << endl;
        break;
      case 1:
        limparTela();

        cout << "=-=-=-=-=-CADASTRAR CIDADE-=-=-=-=-=" << endl << endl;
        cout << "Informe o nome da cidade:" << endl;
        cout << ">>> ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, nomeCidade);
        
        controle.cadastrarCidade(nomeCidade);

        break;
      case 2:
        limparTela();
        cout << "case 2" << endl;
        //cadastrarTrajeto(nomeOrigem, nomeDestino, tipo, distancia);
        break;
      case 3:
        limparTela();

        cout << "=-=-=-=-CADASTRAR TRANSPORTE-=-=-=-=" << endl << endl;
        cout << "Informe o nome do transporte:" << endl;
        cout << ">>> ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, nomeTransporte);

        cout << "Informe o local atual:" << endl;
        cout << ">>> ";
        getline(cin, localAtual);

        cout << "Informe o tipo de transporte [0 - aquático | 1 - terrestre]:" << endl;
        cout << ">>> ";
        cin >> entrada;
        tipo = pedirTipoTransporte(entrada);

        cout << "Informe a capacidade do transporte:" << endl;
        cout << ">>> ";
        cin >> capacidade;

        cout << "Informe a velocidade do transporte (km/h):" << endl;
        cout << ">>> ";
        cin >> velocidade;

        cout << "Informe a distancia entre os descansos (km):" << endl;
        cout << ">>> ";
        cin >> distanciaDescanso;

        cout << "Informe o tempo de descanso (horas):" << endl;
        cout << ">>> ";
        cin >> tempoDescanso;

        controle.cadastrarTransporte(nomeTransporte, tipo, capacidade, velocidade, distanciaDescanso, tempoDescanso, localAtual);
        break;
      case 4:
        limparTela();

        cout << "=-=-=-=-CADASTRAR PASSAGEIRO-=-=-=-=" << endl << endl;
        cout << "Informe o nome do passageiro:" << endl;
        cout << ">>> ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, nomePassageiro);

        cout << "Informe o local atual do passageiro:" << endl;
        cout << ">>> ";
        getline(cin, localAtual);

        controle.cadastrarPassageiro(nomePassageiro, localAtual);
        break;
      case 5:
        cout << "case 5" << endl;
        //iniciarViagem(nomeTransporte, nomesPassageiros, nomeOrigem, nomeDestino);
        break;
      case 6:
        cout << "case 6" << endl;
        //avancarHoras(horas);
        break;
      case 7:
        cout << "case 7" << endl;
        //relatarEstado();
        break;
    } 
  }while(opcao != 0);

  return 0;
}

void menu(int &opcao)
{
  cout << "=-=-=-=-=-=-=-=MENU=-=-=-=-=-=-=-=-=" << endl;
  cout << "0. Sair do sistema" << endl;
  cout << "1. Cadastrar cidade" << endl;
  cout << "2. Cadastrar trajeto" << endl;
  cout << "3. Cadastrar transporte" << endl;
  cout << "4. Cadastrar passageiro" << endl;
  cout << "5. Iniciar viagem" << endl;
  cout << "6. Avançar horas" << endl;
  cout << "7. Relatório de estado" << endl << endl;
  cout << "Informe uma opção:" << endl;
  cout << ">>> ";
  cin >> opcao;
}

void limparTela()
{
  #ifdef _WIN32
    system("CLS");
  #else
    system("clear");
  #endif
}


TipoTransporte pedirTipoTransporte(int entrada)
{
  if(entrada == 0)
  {
    return TipoTransporte::AQUATICO;
  }
  else if(entrada == 1)
  {
    return TipoTransporte::TERRESTRE;
  }
  else
  {
    cout << "AVISO: Não foi informado um tipo de transporte válido, por padrão o tipo é TERRESTRE." << endl;
    return TipoTransporte::TERRESTRE;
  }
}
