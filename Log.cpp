#include "Log.hpp"
#include <fstream>
#include <iostream>

void Log::registrar(const std::string& mensagem) {
    std::ofstream logFile("sistema.log", std::ios_base::app);
    
    if (logFile.is_open()) {
        logFile << mensagem << std::endl;
        logFile.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo de log." << std::endl;
    }
}
