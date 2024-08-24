#include "Persistencia.hpp"
#include <fstream>

void Persistencia::salvar(ControladorDeTransito& controlador, const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);
    
    if (arquivo.is_open()) {
        // Salvar cidades
        // Salvar trajetos
        // Salvar transportes
        // Salvar passageiros
        // Salvar viagens
    }
    
    arquivo.close();
}

void Persistencia::carregar(ControladorDeTransito& controlador, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    
    if (arquivo.is_open()) {
        // Carregar cidades
        // Carregar trajetos
        // Carregar transportes
        // Carregar passageiros
        // Carregar viagens
    }
    
    arquivo.close();
}
