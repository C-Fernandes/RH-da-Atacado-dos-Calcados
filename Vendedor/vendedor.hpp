#ifndef VENDEDOR_HEADER
#define VENDEDOR_HEADER

#include "./Pessoa/pessoa.hpp"
#include "./Funcionario/funcionario.hpp"

class Vendedor : public Pessoa, public Funcionario
{
    char tipoVendedor;

public:
    Vendedor();
    Vendedor(std::string nome, std::string cpf, std::string estadoCivil,int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
             std::string salario, std::string matricula, int dia, int mes, int ano, char tipoVendedor);
    char getTipoVendedor();
    void setTipoVendedor(char tipoVendedor);
    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif