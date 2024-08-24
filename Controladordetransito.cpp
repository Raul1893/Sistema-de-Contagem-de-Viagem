#include "ControladorDeTransito.hpp"
#include <iostream>

void ControladorDeTransito::cadastrarCidade(std::string nome) {
    cidades.push_back(new Cidade(nome));
}

void ControladorDeTransito::cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino, char tipo, int distancia) {
    Cidade* origem = nullptr;
    Cidade* destino = nullptr;

    for (Cidade* cidade : cidades) {
        if (cidade->getNome() == nomeOrigem) {
            origem = cidade;
        } else if (cidade->getNome() == nomeDestino) {
            destino = cidade;
        }
    }

    if (origem && destino) {
        trajetos.push_back(new Trajeto(origem, destino, tipo, distancia));
    } else {
        std::cout << "Origem ou destino não encontrados." << std::endl;
    }
}

void ControladorDeTransito::cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade, int distanciaEntreDescansos, int tempoDeDescanso, std::string nomeCidade) {
    Cidade* cidade = nullptr;

    for (Cidade* c : cidades) {
        if (c->getNome() == nomeCidade) {
            cidade = c;
            break;
        }
    }

    if (cidade) {
        transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade, distanciaEntreDescansos, tempoDeDescanso, cidade));
    } else {
        std::cout << "Cidade não encontrada." << std::endl;
    }
}

void ControladorDeTransito::cadastrarPassageiro(std::string nome, std::string nomeCidade) {
    Cidade* cidade = nullptr;

    for (Cidade* c : cidades) {
        if (c->getNome() == nomeCidade) {
            cidade = c;
            break;
        }
    }

    if (cidade) {
        passageiros.push_back(new Passageiro(nome, cidade));
    } else {
        std::cout << "Cidade não encontrada." << std::endl;
    }
}

void ControladorDeTransito::criarViagem(std::string nomeTransporte, std::vector<std::string> nomesPassageiros, std::string nomeOrigem, std::string nomeDestino) {
    Transporte* transporte = nullptr;
    Cidade* origem = nullptr;
    Cidade* destino = nullptr;
    std::vector<Passageiro*> passageirosNaViagem;

    for (Transporte* t : transportes) {
        if (t->getNome() == nomeTransporte) {
            transporte = t;
            break;
        }
    }

    for (Cidade* c : cidades) {
        if (c->getNome() == nomeOrigem) {
            origem = c;
        } else if (c->getNome() == nomeDestino) {
            destino = c;
        }
    }

    for (std::string nomePassageiro : nomesPassageiros) {
        for (Passageiro* p : passageiros) {
            if (p->getNome() == nomePassageiro && p->getLocalAtual() == origem) {
                passageirosNaViagem.push_back(p);
                break;
            }
        }
    }

    if (transporte && origem && destino && !passageirosNaViagem.empty()) {
        Viagem* viagem = new Viagem(transporte, passageirosNaViagem, origem, destino);
        viagens.push_back(viagem);
        viagem->iniciarViagem();
    } else {
        std::cout << "Dados insuficientes para criar a viagem." << std::endl;
    }
}

void ControladorDeTransito::avancarTempo(int horas) {
    for (Viagem* viagem : viagens) {
        if (viagem->isEmAndamento()) {
            viagem->avancarHoras(horas);
        }
    }
}

void ControladorDeTransito::gerarRelatorio() const {
    std::cout << "Relatório de Viagens:" << std::endl;

    for (Viagem* viagem : viagens) {
        viagem->relatarEstado();
    }
}
