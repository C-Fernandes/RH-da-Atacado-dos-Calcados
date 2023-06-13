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
char Vendedor::getTipoVendedor() { return this->tipoVendedor; };
void Vendedor::setTipoVendedor(char tipoVendedor) { this->tipoVendedor = tipoVendedor; };
float Vendedor::calcularSalario(int diasFaltas)
{
    float salario = stof(getSalario()) - ((stof(getSalario()) / 30) * diasFaltas);

    if (this->tipoVendedor == 'A')
        salario += stof(getSalario()) * 0.25;
    if (this->tipoVendedor == 'B')
        salario += stof(getSalario()) * 0.1;
    if (this->tipoVendedor == 'C')
        salario += stof(getSalario()) * 0.05;
    salario += getQuantFilhos() * 100;
    return salario;
};
float Vendedor::calcularRecisao(Data desligamento)
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