#include <queue>
#include <algorithm>
#include <limits>
#include "../include/dijkstra.hpp"

using namespace std;

GrafoCidade::GrafoCidade(unordered_map<string, list<pair<string, double>>> grafoCidade)
{
  this->grafoCidade = grafoCidade;
}

void GrafoCidade::adicionarTrajeto(const string origem, const string destino, double distancia)
{
  this->grafoCidade[origem].emplace_back(destino, distancia);
  this->grafoCidade[destino].emplace_back(origem, distancia);
}

vector<string> GrafoCidade::caminhoCurto(const string inicio, const string fim)
{
  unordered_map<string, double> distancias;
  unordered_map<string, string> pai;
  priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq;

  for (const auto& par : grafoCidade)
  {
    distancias[par.first] = numeric_limits<double>::infinity();
  }
  distancias[inicio] = 0.0;
  pq.emplace(0.0, inicio);

  while (!pq.empty())
  {
    pair<double, string> topo = pq.top();
    double distanciaAtual = topo.first;
    string atual = topo.second;
    pq.pop();

    if (atual == fim) {
      vector<string> caminho;
      for (string em = fim; em != ""; em = pai[em])
      {
        caminho.push_back(em);
      }
      reverse(caminho.begin(), caminho.end());
      return caminho;
    }

    for (const auto& parVizinho : grafoCidade[atual])
    {
      string vizinho = parVizinho.first;
      double peso = parVizinho.second;
      double distancia = distanciaAtual + peso;
      if (distancia < distancias[vizinho])
      {
        distancias[vizinho] = distancia;
        pai[vizinho] = atual;
        pq.emplace(distancia, vizinho);
      }
    }
  }

  return {};
}
