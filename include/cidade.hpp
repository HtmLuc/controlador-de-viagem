#ifndef CIDADE_HPP
#define CIDADE_HPP

#include <string>

using namespace std;

class Cidade
{
  private:
    string nome;
  public:
    Cidade(string nome);
    string getNome();
};

#endif
