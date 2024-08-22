#ifndef DIJKSTRA_GRAFO_HPP
#define DIJKSTRA_GRAFO_HPP

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

class GrafoCidade
{
  private:
    unordered_map<string, list<pair<string, double>>> grafoCidade;

  public:
    GrafoCidade(unordered_map<string, list<pair<string, double>>> grafoCidade);
    void adicionarTrajeto(const string origem, const string destino, double distancia);
    vector<string> caminhoCurto(const string inicio, const string fim);
};

#endif
