#ifndef CIDADE_HPP
#define CIDADE_HPP

#include <string>

using std::string;

class Cidade
{
  private:
    string nome;
  public:
    Cidade( string nome );
    string getNome();
};

#endif
