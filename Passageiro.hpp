#ifndef PASSAGEIRO_HPP
#define PASSAGEIRO_HPP

#include "Cidade.hpp"

class Passageiro {
private:
    std::string nome;
    Cidade* localAtual;

public:
    Passageiro(std::string nome, Cidade* localAtual);
    std::string getNome() const;
    Cidade* getLocalAtual() const;
    void setLocalAtual(Cidade* local);
};

#endif
