#include "pessoa.hpp"
using namespace std;
Pessoa::Pessoa(){};
Pessoa::Pessoa(std::string nome, std::string cpf, int dia, int mes, int ano, std::string estadoCivil, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos)
{
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento.dia = dia;
    this->dataNascimento.mes = mes;
    this->dataNascimento.ano = ano;
    this->EnderecoPessoal.bairro = bairro;
    this->EnderecoPessoal.rua = rua;
    this->EnderecoPessoal.cep = cep;
    this->EnderecoPessoal.numero = numero;
    this->EnderecoPessoal.cidade = cidade;
    this->quantFilhos = quantFilhos;
    this->estadoCivil = estadoCivil;
};
std::string Pessoa::getNome() { return this->nome; };
void Pessoa::setNome(std::string nome) { this->nome = nome; };
std::string Pessoa::getCpf() { return this->cpf; };
void Pessoa::setCpf(std::string cpf) { this->cpf = cpf; };
Data Pessoa::getDataNascimento() { return this->dataNascimento; };
void Pessoa::setDataNascimento(int dia, int mes, int ano)
{
    this->dataNascimento.dia = dia;
    this->dataNascimento.mes = mes;
    this->dataNascimento.ano = ano;
};
std::string Pessoa::getEstadoCivil() { return this->estadoCivil; };
void Pessoa::setEstadoCivil(std::string estadoCivil) { this->estadoCivil = estadoCivil; };
Endereco Pessoa::getEnderecoPessoal() { return this->EnderecoPessoal; };
void Pessoa::setEnderecoPessoal(std::string cidade, std::string bairro, std::string rua, std::string cep, int numero)
{
    this->EnderecoPessoal.bairro = bairro;
    this->EnderecoPessoal.cep = cep;
    this->EnderecoPessoal.cidade = cidade;
    this->EnderecoPessoal.numero = numero;
    this->EnderecoPessoal.rua = rua;
}
int Pessoa::getQuantFilhos() { return this->quantFilhos; };
void Pessoa::setQuantFilhos(int quatFilhos) { this->quantFilhos = quatFilhos; };
;
