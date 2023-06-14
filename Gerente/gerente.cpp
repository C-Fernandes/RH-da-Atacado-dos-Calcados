#include "gerente.hpp"
#include <math.h>
using namespace std;
Gerente::Gerente(){};
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
    float salario = stof(getSalario()) - ((stof(getSalario()) / 30) * diasFaltas); //Pega o salario e diminui as faltas
    salario += this->participacaoLucros; //Adiciona a participação nos lucros
    salario += getQuantFilhos() * 100; // E adiciona o valor pela quantidade de filhos
    return salario;
};
float Gerente::calcularRecisao(Data desligamento)
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