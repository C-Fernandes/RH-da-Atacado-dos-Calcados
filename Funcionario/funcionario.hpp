#ifndef FUNCIONARIO_HEADER
#define FUNCIONARIO_HEADER
#include "../util.hpp"
class Funcionario
{
    std::string salario, matricula;
    Data ingressoEmpresa;

public:
    virtual float calcularSalario(int diasFaltas) = 0;
    virtual float calcularRecisao(Data desligamento) = 0;
    std::string getSalario();
    void setSalario(std::string salario);
    std::string getMatricula();
    void setMatricula(std::string matricula);
    Data getIngressoEmpresa();
    void setIngressoEmpresa(int dia, int mes, int ano);
};

#endif