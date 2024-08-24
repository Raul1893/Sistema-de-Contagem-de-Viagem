/**
 * @brief Classe que representa uma cidade.
 */
class Cidade {
private:
    std::string nome; ///< Nome da cidade.

public:
    /**
     * @brief Construtor que inicializa a cidade com um nome.
     * @param nome Nome da cidade.
     */
    Cidade(std::string nome);

    /**
     * @brief Retorna o nome da cidade.
     * @return Nome da cidade.
     */
    std::string getNome() const;
};
