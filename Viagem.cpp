#include "Viagem.hpp"
#include <iostream>

Viagem::Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros,
               Cidade* origem, Cidade* destino)
    : transporte(transporte), passageiros(passageiros), origem(origem), destino(destino),
      horasEmTransito(0), emAndamento(false) {}

void Viagem::iniciarViagem() {
    if (transporte->getLocalAtual() == origem) {
        emAndamento = true;
        std::cout << "Viagem de " << origem->getNome() << " para " << destino->getNome()
                  << " iniciada." << std::endl;
    } else {
        std::cout << "O transporte não está na cidade de origem." << std::endl;
    }
}

void Viagem::avancarHoras(int horas) {
    if (emAndamento) {
        horasEmTransito += horas;
        int distanciaPercorrida = transporte->getVelocidade() * horas;

        if (distanciaPercorrida >= transporte->getDistanciaEntreDescansos()) {
            horasEmTransito += transporte->getTempoDeDescanso();
        }

        int distanciaRestante = origem->getDistancia() - distanciaPercorrida;

        if (distanciaRestante <= 0) {
            emAndamento = false;
            transporte->setLocalAtual(destino);
            for (Passageiro* passageiro : passageiros) {
                passageiro->setLocalAtual(destino);
            }
            std::cout << "Viagem concluída. Chegada em " << destino->getNome() << "." << std::endl;
        }
    }
}

void Viagem::relatarEstado() const {
    std::cout << "Viagem de " << origem->getNome() << " para " << destino->getNome()
              << " está " << (emAndamento ? "em andamento." : "concluída.") << std::endl;
}

bool Viagem::isEmAndamento() const {
    return emAndamento;
}
