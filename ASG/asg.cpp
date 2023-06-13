#include "asg.hpp"
#include <iostream>
#include <math.h>
using namespace std;

Asg::Asg(std::string nome, std::string cpf, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
         float adicionalInsalubridade, std::string salario, std::string matricula, int dia, int mes, int ano)
{
    this->adicionalInsalubridade = adicionalInsalubridade;
    setSalario(salario);
    setMatricula(matricula);
    setIngressoEmpresa(diaN, mesN, anoN);
    setNome(nome);
    setCpf(cpf);
    setDataNascimento(dia, mes, ano);
    setEnderecoPessoal(cidade, bairro, rua, cep, numero);
    setQuantFilhos(quantFilhos);
    setIngressoEmpresa(dia, mes, ano);
};
float Asg::getAdicionalInsalubridade() { return this->adicionalInsalubridade; };
void Asg::setAdicionalInsalubridade(float adicionalInsalubridade) { this->adicionalInsalubridade = adicionalInsalubridade; };
float Asg::calcularSalario(int diasFaltas)
{
    string salarioS = getSalario();
    float salario = stof(salarioS);
    salario -= (salario / 30) * diasFaltas;
    salario += (this->adicionalInsalubridade * (salario));
    salario += getQuantFilhos() * 100;
    return salario;
};
float Asg::calcularRecisao(Data desligamento)
{
    
    float ganhoRDia = stof(getSalario()) / 365;
    float ganhoPMes = stof(getSalario()) / 12;
    int quantAnos = fabs(getIngressoEmpresa().ano - desligamento.ano);
    int quantMes = getIngressoEmpresa().mes - desligamento.mes;
    int quantDias = fabs(getIngressoEmpresa().dia - desligamento.dia);
    if (quantMes == 0)
        quantMes = 12;
    if (quantMes > 0)
        quantMes = 12 - quantMes;
    if (quantMes < 0)
        quantMes = 12 + fabs(quantMes);
    if (quantAnos > 1)
        quantMes += 12 * (quantAnos - 1);

    float valor = (ganhoRDia * quantDias) + (ganhoPMes * quantMes);
    return valor;
};