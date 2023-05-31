#ifndef PESSOA_HEADER
#define PESSOA_HEADER
#include "./util.hpp"
#include <iostream>
class Pessoa
{
    std::string nome, cpf, dataNascimento, estadoCivil;
    Endereco EnderecoPessoal;
    int quantFilhos;

public:
    Pessoa();
    Pessoa(std::string nome, std::string cpf, std::string dataNasciment,  std::string estadoCivil,std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos);
    std::string getNome();
    void setNome(std::string nome);
    std::string getCpf();
    void setCpf(std::string cpf);
    std::string getDataNascimento();
    void setDataNascimento(std::string dataNascimento);
    std::string getEstadoCivil();
    void setEstadoCivil(std::string estadoCivil);
    Endereco getEnderecoPessoal();
    void setEnderecoPessoal(std::string cidade, std::string bairro, std::string rua, std::string cep, int numero);
    int getQuantFilhos();
    void setQuantFilhos(int quatFilhos);
};
#endif