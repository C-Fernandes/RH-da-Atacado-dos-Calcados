#ifndef EMPRESA_HEADER
#define EMPRESA_HEADER

#include "./Vendedor/vendedor.hpp"
#include "./ASG/asg.hpp"
#include "./Gerente/gerente.hpp"
#include <vector>

class Empresa
{
    float faturamentoMensal;
    std::string nomeEmpresa, cnpj;
    Pessoa dono;
    std::vector<Asg> asgs;
    std::vector<Vendedor> vendedores;
    std::vector<Gerente> gerentes;
    Data hoje;

public:
    Empresa();
    Empresa(std::string nomeEmpresa, std::string cnpj, float faturamentoMensal, int dia, int mes, int ano);
    float getFaturamentoMensal();
    void setFaturamentoMensal(float faturamento);
    std::string getNomeEmpresa();
    void setNomeEmpresa(std::string nomeEmpresa);
    std::string getCnpj();
    void setCnpj(std::string cnpj);
    Pessoa getDono();
    std::vector<Asg> getAsg();
    std::vector<Vendedor> getVendedores();
    std::vector<Gerente> getGerentes();
    void carregaFuncoes();
    void carregarEmpresa();
    void carregarAsg();
    void carregarVendedor();
    void carregarGerente();
    void carregarDono();
    void imprimeAsgs();
    void imprimeVendendores();
    void imprimeGerentes();
    void imprimeDono();
    void buscaFuncionario(int matricula);
    void cacularSalarioFuncionario(int matricula);
    void calcularTodoOsSalarios();
    void calcularRecisao(int matricula, Data desligamento);
};
#endif