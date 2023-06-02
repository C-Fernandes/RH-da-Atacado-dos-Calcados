#include "gerente.hpp"

Gerente::Gerente(std::string nome, std::string cpf, std::string estadoCivil, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
                 std::string salario, std::string matricula, int dia, int mes, int ano, float participacaoLucros)
{
    setNome(nome);
    setCpf(cpf);
    setEstadoCivil(estadoCivil);
    setDataNascimento(dia, mes, ano);
    setEnderecoPessoal(cidade, bairro, rua, cep, numero);
    setQuantFilhos(quantFilhos);
    setSalario(salario);
    setMatricula(matricula);
    setIngressoEmpresa(dia, mes, ano);
    this->participacaoLucros = participacaoLucros;
};

float Gerente::getParticipacaoLucros() { return this->participacaoLucros; };
void Gerente::setParticipacaoLucros(float participacaoLucros) { this->participacaoLucros = participacaoLucros; };
float Gerente::calcularSalario(int diasFaltas){};
float Gerente::calcularRecisao(Data desligamento){};