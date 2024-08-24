#include "ControladorDeTransito.hpp"
#include "Persistencia.hpp"
#include "Log.hpp"
#include <iostream>

int main() {
    ControladorDeTransito controlador;
    int opcao = 0;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Cadastrar Cidade" << std::endl;
        std::cout << "2. Cadastrar Trajeto" << std::endl;
        std::cout << "3. Cadastrar Transporte" << std::endl;
        std::cout << "4. Cadastrar Passageiro" << std::endl;
        std::cout << "5. Criar Viagem" << std::endl;
        std::cout << "6. Avançar Tempo" << std::endl;
        std::cout << "7. Gerar Relatório" << std::endl;
        std::cout << "8. Salvar Dados" << std::endl;
        std::cout << "9. Carregar Dados" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                std::string nomeCidade;
                std::cout << "Nome da Cidade: ";
                std::cin >> nomeCidade;
                controlador.cadastrarCidade(nomeCidade);
                Log::registrar("Cidade cadastrada: " + nomeCidade);
                break;
            }
            case 2: {
                std::string nomeOrigem, nomeDestino;
                char tipo;
                int distancia;
                std::cout << "Nome da Cidade de Origem: ";
                std::cin >> nomeOrigem;
                std::cout << "Nome da Cidade de Destino: ";
                std::cin >> nomeDestino;
                std::cout << "Tipo (A para Aquático, T para Terrestre): ";
                std::cin >> tipo;
                std::cout << "Distância: ";
                std::cin >> distancia;
                controlador.cadastrarTrajeto(nomeOrigem, nomeDestino, tipo, distancia);
                Log::registrar("Trajeto cadastrado entre " + nomeOrigem + " e " + nomeDestino);
                break;
            }
            case 3: {
                std::string nomeTransporte, nomeCidade;
                char tipo;
                int capacidade, velocidade, distanciaEntreDescansos, tempoDeDescanso;
                std::cout << "Nome do Transporte: ";
                std::cin >> nomeTransporte;
                std::cout << "Tipo (A para Aquático, T para Terrestre): ";
                std::cin >> tipo;
                std::cout << "Capacidade: ";
                std::cin >> capacidade;
                std::cout << "Velocidade: ";
                std::cin >> velocidade;
                std::cout << "Distância Entre Descansos: ";
                std::cin >> distanciaEntreDescansos;
                std::cout << "Tempo de Descanso: ";
                std::cin >> tempoDeDescanso;
                std::cout << "Nome da Cidade: ";
                std::cin >> nomeCidade;
                controlador.cadastrarTransporte(nomeTransporte, tipo, capacidade, velocidade, distanciaEntreDescansos, tempoDeDescanso, nomeCidade);
                Log::registrar("Transporte cadastrado: " + nomeTransporte);
                break;
            }
            case 4: {
                std::string nomePassageiro, nomeCidade;
                std::cout << "Nome do Passageiro: ";
                std::cin >> nomePassageiro;
                std::cout << "Nome da Cidade Atual: ";
                std::cin >> nomeCidade;
                controlador.cadastrarPassageiro(nomePassageiro, nomeCidade);
                Log::registrar("Passageiro cadastrado: " + nomePassageiro);
                break;
            }
            case 5: {
                std::string nomeTransporte, nomeOrigem, nomeDestino;
                int quantidadePassageiros;
                std::vector<std::string> nomesPassageiros;

                std::cout << "Nome do Transporte: ";
                std::cin >> nomeTransporte;
                std::cout << "Nome da Cidade de Origem: ";
                std::cin >> nomeOrigem;
                std::cout << "Nome da Cidade de Destino: ";
                std::cin >> nomeDestino;
                std::cout << "Quantidade de Passageiros: ";
                std::cin >> quantidadePassageiros;

                for (int i = 0; i < quantidadePassageiros; ++i) {
                    std::string nomePassageiro;
                    std::cout << "Nome do Passageiro " << i+1 << ": ";
                    std::cin >> nomePassageiro;
                    nomesPassageiros.push_back(nomePassageiro);
                }

                controlador.criarViagem(nomeTransporte, nomesPassageiros, nomeOrigem, nomeDestino);
                Log::registrar("Viagem criada de " + nomeOrigem + " para " + nomeDestino);
                break;
            }
            case 6: {
                int horas;
                std::cout << "Avançar quantas horas? ";
                std::cin >> horas;
                controlador.avancarTempo(horas);
                Log::registrar("Tempo avançado em " + std::to_string(horas) + " horas");
                break;
            }
            case 7: {
                controlador.gerarRelatorio();
                break;
            }
            case 8: {
                std::string nomeArquivo;
                std::cout << "Nome do arquivo para salvar: ";
                std::cin >> nomeArquivo;
                Persistencia::salvar(controlador, nomeArquivo);
                Log::registrar("Dados salvos no arquivo: " + nomeArquivo);
                break;
            }
            case 9: {
                std::string nomeArquivo;
                std::cout << "Nome do arquivo para carregar: ";
                std::cin >> nomeArquivo;
                Persistencia::carregar(controlador, nomeArquivo);
                Log::registrar("Dados carregados do arquivo: " + nomeArquivo);
                break;
            }
            case 0:
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
                break;
        }

    } while (opcao != 0);

    return 0;
}
