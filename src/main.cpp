#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include "../include/controladorDeTransito.hpp"

using namespace std;

void menu(int&);

void limparTela();

int main()
{
  ControladorDeTransito controle;
  int opcao;
  string nomeCidade, nomeTransporte, localAtual, nomePassageiro, nomeOrigem, nomeDestino;
  int capacidade, tempoDescanso, entrada, tipo;
  float velocidade, distanciaDescanso, distanciaTrajeto;
  
  cout << "┌─────────────────────────────────────────────────┐" << endl;
  cout << "│Bem-vindo ao sistema de gerenciamento de viagens!│" << endl;
  cout << "└─────────────────────────────────────────────────┘" << endl << endl;
  
  // Puxando informações dos arquivos
  controle.carregarCidades();
  controle.carregarTransportes();

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

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while(true)
        {
          cout << "Informe o nome da cidade:" << endl;
          cout << ">>> ";
          getline(cin, nomeCidade);
          if(controle.verificarCidade(nomeCidade))
          {
            cout << "\033[31mERRO: Cidade informada já existe. Tente novamente!\033[0m" << endl;
          }
          else
          {
            break;
          }
        } 

        controle.cadastrarCidade(nomeCidade);

        break;
      case 2:
        limparTela();
        cout << "=-=-=-=-CADASTRAR TRAJETO-=-=-=-=" << endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while(true)
        {
          cout << "Informe o nome da cidade de origem:" << endl;
          cout << ">>> ";
          getline(cin, nomeOrigem);

          if(!controle.verificarCidade(nomeOrigem))
          {
            cout << "\033[31mERRO: Cidade informada não existe. Tente novamente\033[0m" << endl;
            continue;
          }
          else
          {
            break;
          }
        }

        while(true)
        {
          cout << "Informe o nome da cidade de destino:" << endl;
          cout << ">>> ";
          getline(cin, nomeDestino);
          if(nomeDestino == nomeOrigem)
          {
            cout << "\033[31mERRO: O local de destino deve ser diferente do de origem. Tente novamente!\033[0m" << endl;
            continue;
          }
          else if(!controle.verificarCidade(nomeDestino))
          {
            cout << "\033[31mERRO: Cidade informada não existe. Tente novamente\033[0m" << endl;
            continue;
          }
          else
          {
            break;
          }
        }
        cout << "Informe o tipo do trajeto [0 - aquático | 1 - terrestre]:" << endl;
        cout << ">>> ";
        cin >> tipo;

        cout << "Informe a distância do trajeto:" << endl;
        cout << ">>> ";
        cin >> distanciaTrajeto;

        controle.cadastrarTrajeto(nomeOrigem, nomeDestino, tipo, distanciaTrajeto);
        break;
      case 3:
        limparTela();

        while(true)
        {
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
         
          cout << "=-=-=-=-CADASTRAR TRANSPORTE-=-=-=-=" << endl << endl;
          cout << "Informe o nome do transporte:" << endl;
          cout << ">>> ";
          getline(cin, nomeTransporte);

          while(true)
          {
            cout << "Informe o local atual do transporte:" << endl;
            cout << ">>> ";
            getline(cin, localAtual);
            if(!controle.verificarCidade(localAtual))
            {
              cout << "\033[31mERRO: Cidade informado não está cadastrado. Informe outro nome!\033[0m" << endl;
              continue;
            }
            break;
          }

          cout << "Informe o tipo de transporte [0 - aquático | 1 - terrestre]:" << endl;
          cout << ">>> ";
          cin >> tipo;

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

          if(controle.verificarTransporte(nomeTransporte, tipo, capacidade, velocidade, distanciaDescanso, tempoDescanso, localAtual))
          {
            cout << "\033[31mERRO: Transporte informado já existe. Tente novamente!\033[0m" << endl;
            continue;
          }
          else
          {
            break;
          }
        }

        controle.cadastrarTransporte(nomeTransporte, tipo, capacidade, velocidade, distanciaDescanso, tempoDescanso, localAtual);
        break;
      case 4:
        limparTela();

        cout << "=-=-=-=-CADASTRAR PASSAGEIRO-=-=-=-=" << endl << endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while(true)
        {
          cout << "Informe o local atual do passageiro:" << endl;
          cout << ">>> ";
          getline(cin, localAtual);
          if(!controle.verificarCidade(localAtual))
          {
            cout << "\033[31mERRO: Cidade informado não está cadastrada. Tente novamente!\033[0m" << endl;
            continue;
          }

          cout << "Informe o nome do passageiro:" << endl;
          cout << ">>> ";
          getline(cin, nomePassageiro);
          if(controle.verificarPassageiro(nomePassageiro, localAtual))
          {
            cout << "\033[31mERRO: Passageiro informado já está cadastrado nessa localização. Tente novamente!\033[0m" << endl;
            continue;
          }
          break;
        }
        controle.cadastrarPassageiro(nomePassageiro, localAtual);
        break;
      case 5:
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "case 5" << endl;
        //iniciarViagem(nomeTransporte, nomesPassageiros, nomeOrigem, nomeDestino);
        break;
      case 6:
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "case 6" << endl;
        //avancarHoras(horas);
        break;
      case 7:
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
