#ifndef PESSOA_HEADER
#define PESSOA_HEADER
#include "../util.hpp"
#include <iostream>
class Pessoa
{
    std::string nome, cpf, estadoCivil;
    Data dataNascimento;
    Endereco EnderecoPessoal;
    int quantFilhos;

public:
    Pessoa();
    Pessoa(std::string nome, std::string cpf,int dia, int mes, int ano,  std::string estadoCivil,std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos);
    std::string getNome();
    void setNome(std::string nome);
    std::string getCpf();
    void setCpf(std::string cpf);
    Data getDataNascimento();
    void setDataNascimento(int dia, int mes, int ano);
    std::string getEstadoCivil();
    void setEstadoCivil(std::string estadoCivil);
    Endereco getEnderecoPessoal();
    void setEnderecoPessoal(std::string cidade, std::string bairro, std::string rua, std::string cep, int numero);
    int getQuantFilhos();
    void setQuantFilhos(int quatFilhos);
};
#endif