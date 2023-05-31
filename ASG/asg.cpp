#include "asg.hpp"
#include <iostream>
#include <math.h>
using namespace std;

float Asg::calcularSalario(int diasFaltas)
{
    string salarioS = getSalario();
    double salario = stod(salarioS);
    salario -= diasFaltas * 50;
    salario += (this->adicionalInsalubridade * (salario));
    salario += getQuantFilhos() * 100;
};
float Asg::calcularRecisao(Data desligamento){

};
Asg::Asg(std::string nome, std::string cpf, std::string dataNasciment, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
         float adicionalInsalubridade, std::string salario, std::string matricula, int dia, int mes, int ano)
{
    this->adicionalInsalubridade = adicionalInsalubridade;
    setSalario(salario);
    setMatricula(matricula);
    setIngressoEmpresa(dia, mes, ano);
    setNome(nome);
    setCpf(cpf);
    setDataNascimento(dataNasciment);
    setEnderecoPessoal(cidade, bairro, rua, cep, numero);
    setQuantFilhos(quantFilhos);
    setIngressoEmpresa(dia, mes, ano);
};
float Asg::getAdicionalInsalubridade(){};
void Asg::setAdicionalInsalubridade(float adicionalInsalubridade) { this->adicionalInsalubridade = adicionalInsalubridade; };