#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
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
/*vector<string> Empresa::separadorLinha(string leitura)
{
    vector<string> palavras;
    string palavra;
    istringstream separacao(leitura);
    while (getline(separacao, palavra, ' '))
    {
        palavras.push_back(palavra);
    }
    return palavras;
}*/
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
void Empresa::carregarEmpresa(int dia, int mes, int ano)
{
    fstream arq;
    arq.open("./Arquivos/empresa.txt", ios::in);
    string linha;
    int contador;
    vector<string> palavras;
    while (getline(arq, linha))
    {
        palavras = separadorLinha(linha);

        if (contador == 5)
        {
            contador = 0;
        }
        if (contador >= 3)
        {
            palavras.push_back(linha);
        }
        contador++;
    }
    Empresa empresa(palavras[0], palavras[1], stod(palavras[2]), dia, mes, ano);
};
void Empresa::carregarAsg()
{
    fstream arq;
    arq.open("./Arquivos/asg.txt", ios::in);
    string linha;
    int contador = 0, posicao = 0;
    Asg *asgs[3];
    vector<string> palavras;
    while (getline(arq, linha))
    {
        if (contador == 25)
        {
            contador = 0;
            asgs[posicao] = new Asg(palavras[0], palavras[1], stoi(palavras[11]), stoi(palavras[10]),
                                    stoi(palavras[9]), palavras[4], palavras[6], palavras[7],
                                    palavras[5], stoi(palavras[8]), stoi(palavras[2]), stoi(palavras[14]),
                                    palavras[13], palavras[12], stoi(palavras[17]), stoi(palavras[16]),
                                    stoi(palavras[15]));
            posicao++;
        }
        if (contador != 21 && contador != 17 && contador != 13 && contador != 7 && contador > 2)
            palavras.push_back(linha);
        contador++;
    }
};
void Empresa::carregarVendedor()
{
    fstream arq;
    arq.open("./Arquivos/vendedor.txt", ios::in);
    string linha;
    int contador = 0, posicao = 0;
    Vendedor *vendedores[5];
    vector<string> palavras;
    char tipoVendedor;
    while (getline(arq, linha))
    {

        if (contador == 25)
        {
            contador = 0;
            tipoVendedor = (palavras[14])[0];
            vendedores[posicao] = new Vendedor(palavras[0], palavras[1], palavras[3],
                                               stoi(palavras[11]), stoi(palavras[10]), stoi(palavras[9]), palavras[4],
                                               palavras[6], palavras[7], palavras[5],
                                               stoi(palavras[8]), stoi(palavras[2]), palavras[13],
                                               palavras[12], stoi(palavras[17]), stoi(palavras[16]),
                                               stoi(palavras[15]), tipoVendedor);
            posicao++;
        }
        if (contador != 21 && contador != 17 && contador != 13 && contador != 7 && contador > 2)
            palavras.push_back(linha);
        contador++;
    }
};
void Empresa::carregarGerente()
{
    fstream arq;
    arq.open("./Arquivos/gerente.txt", ios::in);
    string linha;
    int contador = 0;
    vector<string> palavras;
    while (getline(arq, linha))
    {

        if (contador == 25)
        {
            contador = 0;
            Gerente gerente(palavras[0], palavras[1], palavras[4], stoi(palavras[12]),
                            stoi(palavras[11]), stoi(palavras[10]), palavras[5],
                            palavras[7], palavras[8], palavras[6], stoi(palavras[9]),
                            stoi(palavras[3]), palavras[14], palavras[13], stoi(palavras[18]),
                            stoi(palavras[17]), stoi(palavras[16]), stod(palavras[15]));
        }
        if (contador != 21 && contador != 17 && contador != 13 && contador != 7 && contador > 2)
            palavras.push_back(linha);
        contador++;
    }
};
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
        }
        if (contador >= 3)
        {
            palavras.push_back(linha);
        }
        contador++;
    }
    Pessoa donoF(palavras[0], palavras[1], stoi(palavras[11]), stoi(palavras[10]), stoi(palavras[9]), palavras[3], palavras[4], palavras[6], palavras[7], palavras[5], stoi(palavras[8]), stoi(palavras[2]));
    this->dono = donoF;
};
void Empresa::imprimeAsgs(){};
void Empresa::imprimeVendendores(){};
void Empresa::imprimeGerentes(){};
void Empresa::imprimeDono(){};
void Empresa::buscaFuncionario(int matricula){};
void Empresa::cacularSalarioFuncionario(int matricula){};
void Empresa::calcularTodoOsSalarios(){};
void Empresa::calcularRecisao(int matricula, Data desligamento){};
