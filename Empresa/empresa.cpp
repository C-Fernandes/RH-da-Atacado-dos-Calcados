#include <iostream>
#include <fstream>
#include <sstream>
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
Pessoa Empresa::getDono() { return this->dono; };
vector<Asg> Empresa::getAsg() { return this->asgs; };
vector<Vendedor> Empresa::getVendedores() { return this->vendedores; };
vector<Gerente> Empresa::getGerentes() { return this->gerentes; };
vector<string> Empresa::separadorLinha(string leitura)
{
    vector<string> palavras;
    string palavra;
    istringstream separacao(leitura);
    while (getline(separacao, palavra, ' '))
    {
        palavras.push_back(palavra);
    }
    return palavras;
}
void Empresa::carregarFuncoes()
{
    fstream arq;
    arq.open("./Arquivos/funcoes.txt", ios::in);
    string linha;
    vector<string> palavras;
    while (getline(arq, linha))
    {
        palavras = separadorLinha(linha);
    }
};
void Empresa::carregarEmpresa()
{
    fstream arq;
    arq.open("./Arquivos/empresa.txt", ios::in);
    string linha;
    vector<string> palavras;
    while (getline(arq, linha))
    {
        palavras = separadorLinha(linha);
    }
};
void Empresa::carregarAsg(){};
void Empresa::carregarVendedor(){};
void Empresa::carregarGerente(){};
void Empresa::carregarDono()
{
    
    fstream arq;
    arq.open("./Arquivos/empresa.txt", ios::in);
    string linha;
    int contador = 0;
    vector<string> palavras;
    while (getline(arq, linha))
    {
        if (contador == 13)
        {
            contador = 0;
            
        }if (contador >= 3)
            {
                palavras.push_back(linha);
            }
        contador++;
    }Pessoa dono(palavras[0], palavras[1], stoi(palavras[12]), stoi(palavras[11]), stoi(palavras[10]), palavras[3]), palavras[4], palavras[6], palavras[7], palavras[8], palavras[5], );
};
void Empresa::imprimeAsgs(){};
void Empresa::imprimeVendendores(){};
void Empresa::imprimeGerentes(){};
void Empresa::imprimeDono(){};
void Empresa::buscaFuncionario(int matricula){};
void Empresa::cacularSalarioFuncionario(int matricula){};
void Empresa::calcularTodoOsSalarios(){};
void Empresa::calcularRecisao(int matricula, Data desligamento){};
