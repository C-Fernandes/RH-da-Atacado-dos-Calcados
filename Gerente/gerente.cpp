#include "gerente.hpp"
#include <math.h>

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
float Gerente::calcularSalario(int diasFaltas)
{
    double salario = stod(getSalario()) - (stod(getSalario()) / 30) * diasFaltas;
    salario += stod(getSalario()) * this->participacaoLucros;
    salario += getQuantFilhos() * 100;
    return salario;
};
float Gerente::calcularRecisao(Data desligamento){
      int ganhoRDia = stod(getSalario())/365;
    int quantAnos = getIngressoEmpresa().ano - desligamento.ano;
    int quantMes = getIngressoEmpresa().mes - desligamento.mes;
    int quantDias = getIngressoEmpresa().dia - desligamento.dia;
    if (quantMes == 0)
    {
        quantMes = 12;
    }
    if (quantMes > 0)
    {
        quantMes = 12 - quantMes;
    }
    if (quantMes < 0)
    {
        quantMes = 12 + fabs(quantMes);
    }
    if (quantAnos > 1)
        quantMes += 12 * quantAnos;

    quantDias += quantMes * 30;
    return ganhoRDia * quantDias;
};