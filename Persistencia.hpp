#ifndef PERSISTENCIA_HPP
#define PERSISTENCIA_HPP

#include "ControladorDeTransito.hpp"

class Persistencia {
public:
    static void salvar(ControladorDeTransito& controlador, const std::string& nomeArquivo);
    static void carregar(ControladorDeTransito& controlador, const std::string& nomeArquivo);
};

#endif
