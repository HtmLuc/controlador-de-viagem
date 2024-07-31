#ifndef PASSAGEIRO_HPP
#define PASSAGEIRO_HPP

#include <string>
#include "cidade.hpp"

using std::string;

class Passageiro
{
  private:
    string nome;
    Cidade* localAtual;
  public:
    Passageiro( string nome, Cidade* localAtual );
    string getNome();
    Cidade* getLocalAtual();

    void setLocalAtual( Cidade* local );
};

#endif
