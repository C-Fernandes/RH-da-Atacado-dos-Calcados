#include "vendedor.hpp"

Vendedor::Vendedor(std::string nome, std::string cpf, std::string estadoCivil, std::string dataNasciment, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
                   std::string salario, std::string matricula, int dia, int mes, int ano, char tipoVendedor)
{
    setNome(nome);
    setCpf(cpf);
    setDataNascimento(dataNasciment);
    setEnderecoPessoal(cidade, bairro, rua, cep, numero);
    setSalario(salario);
    setQuantFilhos(quantFilhos);
    setMatricula(matricula);
    setEstadoCivil(estadoCivil);
    setIngressoEmpresa(dia, mes, ano);
    this->tipoVendedor = tipoVendedor;
};
char Vendedor::getTipoVendedor(){
    return this->tipoVendedor;
};
void Vendedor::setTipoVendedor(char tipoVendedor){
    this->tipoVendedor = tipoVendedor;
};
float Vendedor::calcularSalario(int diasFaltas){};
float Vendedor::calcularRecisao(Data desligamento){};