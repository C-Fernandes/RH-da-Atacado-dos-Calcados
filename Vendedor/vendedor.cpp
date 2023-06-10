#include "vendedor.hpp"
#include <math.h>
using namespace std;
Vendedor::Vendedor(std::string nome, std::string cpf, std::string estadoCivil, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
                   std::string salario, std::string matricula, int dia, int mes, int ano, char tipoVendedor)
{
    setNome(nome);
    setCpf(cpf);
    setDataNascimento(diaN, mesN, anoN);
    setEnderecoPessoal(cidade, bairro, rua, cep, numero);
    setSalario(salario);
    setQuantFilhos(quantFilhos);
    setMatricula(matricula);
    setEstadoCivil(estadoCivil);
    setIngressoEmpresa(dia, mes, ano);
    this->tipoVendedor = tipoVendedor;
};
char Vendedor::getTipoVendedor(){return this->tipoVendedor;};
void Vendedor::setTipoVendedor(char tipoVendedor){ this->tipoVendedor = tipoVendedor;};
float Vendedor::calcularSalario(int diasFaltas)
{
    double salario = stod(getSalario()) - (stod(getSalario()) / 30) * diasFaltas;
    if (this->tipoVendedor == 'A')
        salario += stod(getSalario()) * 0.25;
    if (this->tipoVendedor == 'B')
        salario += stod(getSalario()) * 0.1;
    if (this->tipoVendedor == 'C')
        salario += stod(getSalario()) * 0.05;
    salario += getQuantFilhos() * 100;
    return salario;
};
float Vendedor::calcularRecisao(Data desligamento)
{
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