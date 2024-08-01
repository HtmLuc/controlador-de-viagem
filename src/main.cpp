#include <iostream>
#include <string>

using namespace std;

void menu()
{
  cout << "O que você pretende fazer hoje?" << endl << endl;
  cout << "0. Sair do sistema" << endl;
  cout << "1. Cadastrar cidade" << endl;
  cout << "2. Cadastrar trajeto" << endl;
  cout << "3. Cadastrar transporte" << endl;
  cout << "4. Cadastrar passageiro" << endl;
  cout << "5. Iniciar viagem" << endl;
  cout << "6. Avançar horas" << endl;
  cout << "7. Relatório de estado" << endl;
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
      case 1:
        cout << "case 1" << endl;
        //cadastrarCidade(nomeCidade);
      case 2:
        cout << "case 2" << endl;
        //cadastrarTrajeto(nomeOrigem, nomeDestino, tipo, distancia);
      case 3:
        cout << "case 3" << endl;
        //cadastrarTransporte(nome, tipo, capacidade, velocidade, distanciaDescanso, tempoDescanso, localAtual);
      case 4:
        cout << "case 4" << endl;
        //cadastrarPassagegiro(nome, localAtual);
      case 5:
        cout << "case 5" << endl;
        //iniciarViagem(nomeTransporte, nomesPassageiros, nomeOrigem, nomeDestino);
      case 6:
        cout << "case 6" << endl;
        //avancarHoras(horas);
      case 7:
        cout << "case 7" << endl;
        //relatarEstado();
    }
  }while(opcao != 0)

  return 0;
}
