#include <iostream>
#include "empresa.hpp"

using namespace std;

Empresa::Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal, int dia, int mes, int ano)
{
    this->nomeEmpresa = nomeEmpresa;
    this->cnpj = cnpj;
    this->faturamentoMensal = faturamentoMensal;
    this->hoje.dia = dia;
    this->hoje.mes = mes;
    this->hoje.ano = ano;
};
float Empresa::getFaturamentoMensal() { return this->faturamentoMensal; };
void Empresa::setFaturamentoMensal(float faturamento) { this->faturamentoMensal = faturamento; };
string Empresa::getNomeEmpresa() { return this->nomeEmpresa; };
void Empresa::setNomeEmpresa(string nomeEmpresa) { this->nomeEmpresa = nomeEmpresa; };
string Empresa::getCnpj() { return this->cnpj; };
void Empresa::setCnpj(string cnpj) { this->cnpj = cnpj; };
Pessoa Empresa::getDono(){return this->dono;};
vector<Asg> Empresa::getAsg(){return this->asgs;};
vector<Vendedor> Empresa::getVendedores(){return this->vendedores;};
vector<Gerente> Empresa::getGerentes(){return this->gerentes;};
void Empresa::carregaFuncoes(){
    
};
void Empresa::carregarEmpresa();
void Empresa::carregarAsg();
void Empresa::carregarVendedor();
void Empresa::carregarGerente();
void Empresa::carregarDono();
void Empresa::imprimeAsgs();
void Empresa::imprimeVendendores();
void Empresa::imprimeGerentes();
void Empresa::imprimeDono();
void Empresa::buscaFuncionario(int matricula);
void Empresa::cacularSalarioFuncionario(int matricula);
void Empresa::calcularTodoOsSalarios();
void Empresa::calcularRecisao(int matricula, Data desligamento);
