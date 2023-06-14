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
    float salario = stof(getSalario()) - ((stof(getSalario()) / 30) * diasFaltas); //Pega o salario e diminui as faltas

//Verifica o tipo de vendedor e adiciona a porcetagem
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
    
    float ganhoRDia = stof(getSalario()) / 365; //Pega o valor ganho por dia no ano
    float ganhoPMes = stof(getSalario()) / 12; // Pega o valor ganho por mes no ano
    int quantAnos = fabs(getIngressoEmpresa().ano - desligamento.ano); //A quantidade de anos é o modulo do desligamento - ingresso
    int quantMes = getIngressoEmpresa().mes - desligamento.mes; // Quantidade de mês
    int quantDias = fabs(getIngressoEmpresa().dia - desligamento.dia); //Modulo da quantidade de dias
    if (quantMes == 0 && quantAnos>=1) //Se a quantidade de mês é 0, então tem um ano de diferença entre as datas
        quantMes = 12;
    if (quantMes > 0) //Se a quantidade de mês é maior que 0, então tem menos de ano
        quantMes = 12 - quantMes;
    if (quantMes < 0) //Se a quantidade é menor q 0, então tem mais de 1 ano
        quantMes = 12 + fabs(quantMes);
    if (quantAnos > 1) //Se tiver mais de 1, soma a quantidade de meses
        quantMes += 12 * (quantAnos - 1);

    float valor = (ganhoRDia * quantDias) + (ganhoPMes * quantMes); // Soma o produto dos dias com o valor por dia e da quantidade de mes com o ganho por mes
    return valor;
};