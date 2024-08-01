#include "../class/transporte.hpp"

Transporte::Transporte( string nome, TipoTransporte tipo, int capacidade, float velocidade, float distancia_entre_descansos, int tempo_de_descanso, Cidade* localAtual ){
    this->nome = nome;
    this->tipo = tipo;
    this->capacidade = capacidade;
    this->velocidade = velocidade;
    this->distancia_entre_descansos = distancia_entre_descansos;
    this->tempo_de_descanso = tempo_de_descanso;
    this->localAtual = localAtual;
}

string Transporte::getNome()
{
    return nome;
}

TipoTransporte Transporte::getTipo()
{
    return tipo;
}

int Transporte::getCapacidade()
{
    return capacidade;
}

float Transporte::getVelocidade()
{
    return velocidade;
}

float Transporte::getDistanciaEntreDescansos()
{
    return distancia_entre_descansos;
}

int Transporte::getTempoDeDescanso()
{
    return tempo_de_descanso;
}
int Transporte::getTempoDeDescansoAtual(){
    return tempo_de_descanso_atual;
}

Cidade* Transporte::getLocalAtual()
{
    return localAtual;
}

void Transporte::setLocalAtual( Cidade* cidade )
{
    this->localAtual = cidade;
}