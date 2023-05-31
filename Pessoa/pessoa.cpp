#include "pessoa.hpp"

Pessoa::Pessoa(std::string nome, std::string cpf, std::string dataNasciment, std::string estado, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quatFilhos){};
std::string Pessoa::getNome() { return this->nome; };
void Pessoa::setNome(std::string nome) { this->nome = nome; };
std::string Pessoa::getCpf() { return this->cpf; };
void Pessoa::setCpf(std::string cpf) { this->cpf = cpf; };
std::string Pessoa::getDataNascimento() { return this->dataNascimento; };
void Pessoa::setDataNascimento(std::string dataNascimento) { this->dataNascimento = dataNascimento; };
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
