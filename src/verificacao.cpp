#include "include/controladorDeTransito.hpp"
#include <string>
#include <iostream>

void ControladorDeTransito::verificarCidade(string nome){
  string linha;
  bool cidadeExiste = false;

  // Verifica se a cidade já existe
  for(auto& cidade : listaCidades)
  {
    if(cidade->getNome() == nome)
    {
      cidadeExiste = true;
      break;    
    }
  }

  if(!cidadeExiste){
    cout << "\033[31mERRO: Cidade informada não existe. Tente novamente.\033[0m" << endl;
    return;  
  }

}
