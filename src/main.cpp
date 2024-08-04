#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void menu()
{
  cout << "O que você pretende fazer hoje?" << endl << endl; /*mudar a frase*/
  cout << "0. Sair do sistema" << endl;
  cout << "1. Cadastrar cidade" << endl;
  cout << "2. Cadastrar trajeto" << endl;
  cout << "3. Cadastrar transporte" << endl;
  cout << "4. Cadastrar passageiro" << endl;
  cout << "5. Iniciar viagem" << endl;
  cout << "6. Avançar horas" << endl;
  cout << "7. Relatório de estado" << endl;
}

void limparTela()
{
  #ifdef _WIN32
    system("CLS");
  #else
    system("clear");
  #endif
}

int main()
{
  int opcao;
  
  cout << "Bem-vindo ao sistema de gerenciamento de viagens!" << endl;
  cout << "-------------------------------------------------" << endl << endl;
  
  do
  {
    menu();
    cout << "-------------------------------------------------" << endl << endl;
    cout << "Informe uma opção:" << endl;
    cout << ">>> ";
    cin >> opcao;

    switch(opcao)
    {
      case 0:
        cout << "Até a próxima!" << endl;
        break;
      case 1:
        limparTela();
        cout << "case 1" << endl;
        //cadastrarCidade(nomeCidade);
        break;
      case 2:
        limparTela();
        cout << "case 2" << endl;
        //cadastrarTrajeto(nomeOrigem, nomeDestino, tipo, distancia);
        break;
      case 3:
        cout << "case 3" << endl;
        //cadastrarTransporte(nome, tipo, capacidade, velocidade, distanciaDescanso, tempoDescanso, localAtual);
        break;
      case 4:
        cout << "case 4" << endl;
        //cadastrarPassagegiro(nome, localAtual);
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
