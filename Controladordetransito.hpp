#ifndef CONTROLADORDETRANSITO_HPP
#define CONTROLADORDETRANSITO_HPP

#include "Cidade.hpp"
#include "Trajeto.hpp"
#include "Transporte.hpp"
#include "Passageiro.hpp"
#include "Viagem.hpp"
#include <vector>
#include <string>

class ControladorDeTransito {
private:
    std::vector<Cidade*> cidades;
    std::vector<Trajeto*> trajetos;
    std::vector<Transporte*> transportes;
    std::vector<Passageiro*> passageiros;
    std::vector<Viagem*> viagens;

public:
    void cadastrarCidade(std::string nome);
    void cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino, char tipo, int distancia);
    void cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade, int distanciaEntreDescansos, int tempoDeDescanso, std::string nomeCidade);
    void cadastrarPassageiro(std::string nome, std::string nomeCidade);
    void criarViagem(std::string nomeTransporte, std::vector<std::string> nomesPassageiros, std::string nomeOrigem, std::string nomeDestino);
    void avancarTempo(int horas);
    void gerarRelatorio() const;
};

#endif
