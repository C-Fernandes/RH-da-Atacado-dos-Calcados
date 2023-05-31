#include "funcionario.hpp"

std::string Funcionario::getSalario() { return this->salario; };
void Funcionario::setSalario(std::string salario){this->salario = salario;};
std::string Funcionario::getMatricula() { return this->matricula; };
void Funcionario::setMatricula(std::string matricula){this->matricula = matricula;};
Data Funcionario::getIngressoEmpresa(){return this->ingressoEmpresa;};
void Funcionario::setIngressoEmpresa(int dia, int mes, int ano)
{
    this->ingressoEmpresa.dia = dia;
    this->ingressoEmpresa.mes = mes;
    this->ingressoEmpresa.ano = ano;
};