#ifndef TRANSPORTE_HPP
#define TRANSPORTE_HPP

#include "Cidade.hpp"

class Transporte {
private:
    std::string nome;
    char tipo; // 'A' para Aquático, 'T' para Terrestre
    int capacidade;
    int velocidade;
    int distanciaEntreDescansos;
    int tempoDeDescanso;
    Cidade* localAtual;

public:
    Transporte(std::string nome, char tipo, int capacidade, int velocidade,
               int distanciaEntreDescansos, int tempoDeDescanso, Cidade* localAtual);
    std::string getNome() const;
    char getTipo() const;
    int getCapacidade() const;
    int getVelocidade() const;
    int getDistanciaEntreDescansos() const;
    int getTempoDeDescanso() const;
    Cidade* getLocalAtual() const;
    void setLocalAtual(Cidade* local);
};

#endif
