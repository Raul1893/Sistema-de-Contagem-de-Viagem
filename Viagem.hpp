#ifndef VIAGEM_HPP
#define VIAGEM_HPP

#include "Transporte.hpp"
#include "Passageiro.hpp"
#include <vector>

class Viagem {
private:
    Transporte* transporte;
    std::vector<Passageiro*> passageiros;
    Cidade* origem;
    Cidade* destino;
    int horasEmTransito;
    bool emAndamento;

public:
    Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros,
           Cidade* origem, Cidade* destino);
    void iniciarViagem();
    void avancarHoras(int horas);
    void relatarEstado() const;
    bool isEmAndamento() const;
};

#endif
