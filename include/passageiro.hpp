#ifndef PASSAGEIRO_HPP
#define PASSAGEIRO_HPP

#include <string>
#include "cidade.hpp"

using namespace std;

class Passageiro
{
  private:
    string nome;
    Cidade* localAtual;
    bool emTransito;
  public:
    Passageiro(string nome, Cidade* localAtual);
    string getNome();
    Cidade* getLocalAtual();

    void setLocalAtual(Cidade* local);

    bool getEmTransito();
    void setEmTransito(bool status);
};

#endif
