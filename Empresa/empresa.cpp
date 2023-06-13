#include <iostream>
#include <fstream>

#include <time.h>
#include <vector>
#include "empresa.hpp"

using namespace std;

Empresa::Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal, Data dataHoje)
{
    this->nomeEmpresa = nomeEmpresa;
    this->cnpj = cnpj;
    this->faturamentoMensal = faturamentoMensal;
    this->hoje.dia = dataHoje.dia;
    this->hoje.mes = dataHoje.mes;
    this->hoje.ano = dataHoje.ano;
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
string simplificadorMatricula(string matricula)
{
    // cout << "Entrou no simplificador" << endl;
    string novaMatricula = "";
    for (int i = 0; i < 8; i++)
    {
        // cout << "-" << matricula[i] << "-" << endl;
        if (matricula[i] != '.' && matricula[i] != '-' && matricula[i] != '\n')
        {
            novaMatricula.push_back(matricula[i]);
        }
    }
    // cout << novaMatricula << endl;
    return novaMatricula;
}
int sorteioN(int minimo, int maximo)
{
    unsigned seed = time(0);
    srand(seed);
    int numero = (minimo + (rand() % maximo));

    // cout << "numero sorteado função: " << numero << endl;
    return numero;
}
string Empresa::escolherFuncionario()
{
    int numero = sorteioN(0, 5);
    // cout << "primeiro numero sorteado:" << numero << endl;
    string matricula = "289384289";
    if (numero == 1)
    {
        return matricula; //     cout << "ASGS, tamanho: " << asgs.size() << endl;

        numero = sorteioN(0, asgs.size());
        //   cout << "Entrou no if 0 matricula " << matricula << "numero  " << numero << endl;
        matricula = asgs[numero].getMatricula();
        return matricula; /// cout << "Entrou no if 0 matricula " << matricula << "numero  " << numero << endl;
    }
    if (numero == 2)
    {
        //  cout << "Vendedores, tamanho: " << vendedores.size() << endl;

        numero = sorteioN(0, vendedores.size());
        // cout << "Entrou no if 1 matricula " << matricula << "numero  " << numero << endl;
        matricula = vendedores[numero].getMatricula();
        return matricula; // cout << "Entrou no if 1 matricula " << matricula << "numero  " << numero << endl;
    }
    if (numero == 3)
    {
        //    cout << "Gerentes, tamanho: " << gerentes.size() << endl;

        numero = sorteioN(0, gerentes.size());
        //  cout << "Entrou no if 2 matricula " << matricula << "numero  " << numero << endl;
        matricula = gerentes[numero].getMatricula();
        return matricula;
        // cout << "Entrou no if 2 matricula " << matricula << "numero  " << numero << endl;
    }
    else
    {
        return matricula;
    }
    // cout << "Matricula " << matricula << endl;
}
void Empresa::carregarFuncoes()
{
    fstream arq;
    arq.open("./Arquivos/funcoes.txt", ios::in);
    string linha;
    vector<string> linhas;
    while (getline(arq, linha))
    {
        linhas.push_back(linha);
    }
    for (int i = 0; i < linhas.size(); i++)
    {
        if (linhas[i] == "carregarEmpresa()")
            carregarEmpresa(this->hoje.dia, this->hoje.mes, this->hoje.ano);
        if (linhas[i] == "carregarAsg()")
            carregarAsg();
        if (linhas[i] == "carregarVendedor()")
            carregarVendedor();
        if (linhas[i] == "carregarGerente()")
            carregarGerente();
        if (linhas[i] == "carregaDono()")
            carregarDono();
        if (linhas[i] == "imprimeAsgs()")
            imprimeAsgs();
        if (linhas[i] == "imprimeVendedores()")
            imprimeVendendores();
        if (linhas[i] == "imprimeGerentes()")
            imprimeGerentes();
        if (linhas[i] == "imprimeDono()")
            imprimeDono();
        if (linhas[i] == "buscaFuncionario()")
        {
            string matricula = escolherFuncionario();
            matricula = simplificadorMatricula(matricula);
            buscaFuncionario(stoi(matricula));
            i++;
        }
        if (linhas[i] == "calculaSalarioFuncionario()")
        {
            string matricula = escolherFuncionario();
            matricula = simplificadorMatricula(matricula);
            cacularSalarioFuncionario(stoi(matricula));
            i++;
        }
        if (linhas[i] == "calculaTodoOsSalarios()")
            calcularTodoOsSalarios();
        if (linhas[i] == "calcularRecisao()")
        {
            string matricula = escolherFuncionario();
            matricula = simplificadorMatricula(matricula);
            Data data;
            data.dia = sorteioN(1, 31);
            data.mes = sorteioN(1, 12);
            data.ano = 2023;
            calcularRecisao(stoi(matricula), data);
            break;
        }
    }
    cout << "Arquivo encerrado" << endl;
};
void Empresa::carregarEmpresa(int dia, int mes, int ano)
{
    fstream arq;
    arq.open("./Arquivos/empresa.txt", ios::in);
    string linha;
    int contador;
    while (getline(arq, linha))
    {

        if (contador == 5)
        {
            contador = 0;
        }
        if (contador >= 2)
        {
            cout << linha << endl;
        }
        contador++;
    }
};
void Empresa::carregarAsg()
{
    fstream arq;
    arq.open("./Arquivos/asg.txt", ios::in);
    string linha;
    int contador = 0, posicao = 0;
    vector<string> palavras;
    while (getline(arq, linha))
    {
        if (contador != 21 && contador != 17 && contador != 13 && contador != 7 && contador > 2)
            palavras.push_back(linha);

        contador++;
        if (contador == 25)
        {
            contador = 0;
            Asg asg(palavras[0], palavras[1], stoi(palavras[11]), stoi(palavras[10]),
                    stoi(palavras[9]), palavras[4], palavras[6], palavras[7],
                    palavras[5], stoi(palavras[8]), stoi(palavras[2]), stoi(palavras[14]),
                    palavras[13], palavras[12], stoi(palavras[17]), stoi(palavras[16]),
                    stoi(palavras[15]));
            this->asgs.push_back(asg);
            palavras.clear();
        }
    }
    cout << asgs.size() << endl;
};
void Empresa::carregarVendedor()
{
    fstream arq;
    arq.open("./Arquivos/vendedor.txt", ios::in);
    string linha;
    int contador = 0;
    vector<string> palavras;
    char tipoVendedor;
    while (getline(arq, linha))
    {
        if (contador != 21 && contador != 17 && contador != 13 && contador != 7 && contador > 2)
            palavras.push_back(linha);
        contador++;
        if (contador == 25)
        {
            contador = 0;
            tipoVendedor = (palavras[14])[0];
            Vendedor vendedor(palavras[0], palavras[1], palavras[3],
                              stoi(palavras[11]), stoi(palavras[10]), stoi(palavras[9]), palavras[4],
                              palavras[6], palavras[7], palavras[5],
                              stoi(palavras[8]), stoi(palavras[2]), palavras[13],
                              palavras[12], stoi(palavras[17]), stoi(palavras[16]),
                              stoi(palavras[15]), tipoVendedor);
            this->vendedores.push_back(vendedor);
            palavras.clear();
        }
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
        if (contador != 21 && contador != 17 && contador != 13 && contador != 7 && contador > 2)
            palavras.push_back(linha);

        contador++;

        if (contador == 25)
        {
            contador = 0;
            Gerente gerente;
            gerente.setNome(palavras[0]);
            gerente.setCpf(palavras[1]);
            gerente.setQuantFilhos(stoi(palavras[2]));
            gerente.setEstadoCivil(palavras[3]);
            gerente.setEnderecoPessoal(palavras[4], palavras[6], palavras[7], palavras[5], stoi(palavras[8]));
            gerente.setDataNascimento(stoi(palavras[11]), stoi(palavras[10]), stoi(palavras[9]));
            gerente.setMatricula(palavras[12]);
            gerente.setSalario(palavras[13]);
            gerente.setParticipacaoLucros(stof(palavras[14]));
            gerente.setIngressoEmpresa(stoi(palavras[17]), stoi(palavras[16]), stoi(palavras[15]));
            this->gerentes.push_back(gerente);

            palavras.clear();
        }
    }
};
void Empresa::carregarDono()
{
    fstream arq;
    arq.open("./Arquivos/dono.txt", ios::in);
    string linha;
    int contador = 0;
    vector<string> palavras;
    while (getline(arq, linha))
    {

        if (contador == 14)
        {
            contador = 0;
        }
        if (contador >= 2)
        {
            palavras.push_back(linha);
        }
        contador++;
    }
    this->dono.setNome(palavras[0]);
    this->dono.setCpf(palavras[1]);
    this->dono.setEstadoCivil(palavras[3]);
    this->dono.setEnderecoPessoal(palavras[4], palavras[6], palavras[7], palavras[5], stoi(palavras[8]));
    this->dono.setDataNascimento(stoi(palavras[11]), stoi(palavras[10]), stoi(palavras[9]));
    this->dono.setQuantFilhos(stoi(palavras[2]));
};
void Empresa::imprimeAsgs()
{
    cout << "#########IMPRIMINDO ASGS##########" << endl;
    for (int i = 0; i < this->asgs.size(); i++)
    {
        cout << "######################################" << endl;
        cout << "############### ASG Nº" << i + 1 << " ##############" << endl;
        cout << "Nome: " << this->asgs[i].getNome() << endl;
        cout << "Cpf: " << this->asgs[i].getCpf() << endl;
        cout << "Estado civil: " << this->dono.getEstadoCivil() << endl;
        cout << "Data nascimento: " << this->asgs[i].getDataNascimento().dia << "/" << this->asgs[i].getDataNascimento().mes << "/" << this->asgs[i].getDataNascimento().ano << endl;
        cout << "Endereço\nCidade: " << this->asgs[i].getEnderecoPessoal().cidade << " - " << this->asgs[i].getEnderecoPessoal().cep << "\nBairro: " << this->asgs[i].getEnderecoPessoal().bairro << "\nRua: " << this->asgs[i].getEnderecoPessoal().rua << ", " << this->asgs[i].getEnderecoPessoal().numero << endl;
        cout << "Quantidade de filhos: " << this->asgs[i].getQuantFilhos() << endl;
        cout << "Adicional de insalubridade: " << this->asgs[i].getAdicionalInsalubridade() << endl;
        cout << "Salario: " << this->asgs[i].getSalario() << endl;
        cout << "Matricula: " << this->asgs[i].getMatricula() << endl;
        cout << "Data ingresso na empresa: " << this->asgs[i].getIngressoEmpresa().dia << "/" << this->asgs[i].getIngressoEmpresa().mes << "/" << this->asgs[i].getIngressoEmpresa().ano << endl;
        cout << "######################################" << endl;
    }
};
void Empresa::imprimeVendendores()
{

    cout << "#########IMPRIMINDO VENDEDORES##########" << endl;
    for (int i = 0; i < this->vendedores.size(); i++)
    {
        cout << "######################################" << endl;
        cout << "############# VENDEDOR Nº" << i + 1 << " #############" << endl;
        cout << "Nome: " << this->vendedores[i].getNome() << endl;
        cout << "Cpf: " << this->vendedores[i].getCpf() << endl;
        cout << "Estado civil: " << this->dono.getEstadoCivil() << endl;
        cout << "Data nascimento: " << this->vendedores[i].getDataNascimento().dia << "/" << this->vendedores[i].getDataNascimento().mes << "/" << this->vendedores[i].getDataNascimento().ano << endl;
        cout << "Endereço\nCidade: " << this->vendedores[i].getEnderecoPessoal().cidade << " - " << this->vendedores[i].getEnderecoPessoal().cep << "\nBairro: " << this->vendedores[i].getEnderecoPessoal().bairro << "\nRua: " << this->vendedores[i].getEnderecoPessoal().rua << ", " << this->vendedores[i].getEnderecoPessoal().numero << endl;
        cout << "Quantidade de filhos: " << this->vendedores[i].getQuantFilhos() << endl;
        cout << "Tipo de vendedor: " << this->vendedores[i].getTipoVendedor() << endl;
        cout << "Salario: " << this->vendedores[i].getSalario() << endl;
        cout << "Matricula: " << this->vendedores[i].getMatricula() << endl;
        cout << "Data ingresso na empresa: " << this->vendedores[i].getIngressoEmpresa().dia << "/" << this->vendedores[i].getIngressoEmpresa().mes << "/" << this->vendedores[i].getIngressoEmpresa().ano << endl;
        cout << "######################################" << endl;
    }
};
void Empresa::imprimeGerentes()
{
    cout << "#########IMPRIMINDO GERENTES##########" << endl;
    for (int i = 0; i < this->gerentes.size(); i++)
    {

        cout << "######################################" << endl;
        cout << "############# GERENTE Nº" << i + 1 << " #############" << endl;
        cout << "Nome: " << this->gerentes[i].getNome() << endl;
        cout << "Cpf: " << this->gerentes[i].getCpf() << endl;
        cout << "Data nascimento: " << this->gerentes[i].getDataNascimento().dia << "/" << this->gerentes[i].getDataNascimento().mes << "/" << this->gerentes[i].getDataNascimento().ano << endl;
        cout << "Estado civil: " << this->dono.getEstadoCivil() << endl;
        cout << "Endereço\nCidade: " << this->gerentes[i].getEnderecoPessoal().cidade << " - " << this->gerentes[i].getEnderecoPessoal().cep << "\nBairro: " << this->gerentes[i].getEnderecoPessoal().bairro << "\nRua: " << this->gerentes[i].getEnderecoPessoal().rua << ", " << this->gerentes[i].getEnderecoPessoal().numero << endl;
        cout << "Quantidade de filhos: " << this->gerentes[i].getQuantFilhos() << endl;
        cout << "Participação Lucros: " << this->gerentes[i].getParticipacaoLucros() << endl;
        cout << "Salario: " << this->gerentes[i].getSalario() << endl;
        cout << "Matricula: " << this->gerentes[i].getMatricula() << endl;
        cout << "Data ingresso na empresa: " << this->gerentes[i].getIngressoEmpresa().dia << "/" << this->gerentes[i].getIngressoEmpresa().mes << "/" << this->gerentes[i].getIngressoEmpresa().ano << endl;
        cout << "######################################" << endl;
    }
};
void Empresa::imprimeDono()
{
    cout << "######################################" << endl;
    cout << "################ DONO ################" << endl;
    cout << "Nome: " << this->dono.getNome() << endl;
    cout << "Cpf: " << this->dono.getCpf() << endl;
    cout << "Estado civil: " << this->dono.getEstadoCivil() << endl;
    cout << "Data nascimento: " << this->dono.getDataNascimento().dia << "/" << this->dono.getDataNascimento().mes << "/" << this->dono.getDataNascimento().ano << endl;
    cout << "Endereço\nCidade: " << this->dono.getEnderecoPessoal().cidade << " - " << this->dono.getEnderecoPessoal().cep << "\nBairro: " << this->dono.getEnderecoPessoal().bairro << "\nRua: " << this->dono.getEnderecoPessoal().rua << ", " << this->dono.getEnderecoPessoal().numero << endl;
    cout << "Quantidade de filhos: " << this->dono.getQuantFilhos() << endl;
    cout << "######################################" << endl;
};
void Empresa::buscaFuncionario(int matricula)
{
    cout << "\nBuscar Funcionario\nMatricula:" << matricula << endl;
    Pessoa funcionario;
    bool encontrado = false;
    string matriculaString = to_string(matricula);
    for (int i = 0; i < gerentes.size(); i++)
    {
        string matriculaUser = simplificadorMatricula(this->gerentes[i].getMatricula());
        if (matriculaUser == matriculaString)
        {
            cout << "Tipo de Funcionario: Gerente\n"
                 << endl;
            funcionario = this->gerentes[i];
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        for (int j = 0; j < vendedores.size(); j++)
        {
            string matriculaUserV = simplificadorMatricula(this->vendedores[j].getMatricula());
            if (matriculaUserV == matriculaString)
            {
                cout << "Tipo de Funcionario: Vendedor\n"
                     << endl;
                funcionario = this->vendedores[j];
                encontrado = true;
            }
        }
    }
    if (!encontrado)
    {
        for (int q = 0; q < asgs.size(); q++)
        {
            string matriculaUserA = simplificadorMatricula(this->asgs[q].getMatricula());
            if (matriculaUserA == matriculaString)
            {

                cout << "Tipo de Funcionario: Asg\n"
                     << endl;
                funcionario = this->asgs[q];
                encontrado = true;
            }
        }
    }
    if (!encontrado)
        cout << "Funcionario não encontrado no sistema!" << endl;
    else
    {
        cout << "Nome: " << funcionario.getNome() << endl;
        cout << "Cpf: " << funcionario.getCpf() << endl;
        cout << "Estado civil: " << funcionario.getEstadoCivil() << endl;
        cout << "Data nascimento: " << funcionario.getDataNascimento().dia << "/" << this->dono.getDataNascimento().mes << "/" << this->dono.getDataNascimento().ano << endl;
        cout << "Endereço\nCidade: " << funcionario.getEnderecoPessoal().cidade << " - " << this->dono.getEnderecoPessoal().cep << "\nBairro: " << this->dono.getEnderecoPessoal().bairro << "\nRua: " << this->dono.getEnderecoPessoal().rua << ", " << this->dono.getEnderecoPessoal().numero << endl;
        cout << "Quantidade de filhos: " << funcionario.getQuantFilhos() << endl;
        cout << "######################################" << endl;
    }
};
void Empresa::cacularSalarioFuncionario(int matricula)
{
    cout << "\nCalcular Salario Funcionario\n"
         << endl;
    cout << "Matricula passada: " << matricula << endl;
    string matriculaString = to_string(matricula);
    int posicao = 0, encontrado = 0;
    // cout << "Matricula string" << matriculaString << endl;

    for (int i = 0; i < gerentes.size(); i++)
    {

        // cout << "Entrou no for de gerentes " << endl;
        string matriculaUser = simplificadorMatricula(this->gerentes[i].getMatricula());
        //   cout << "Matricula:" << matriculaUser << "=" << matriculaString << endl;

        if (matriculaUser == matriculaString)
        {

            //   cout << "Funcionario encontrado!\nTipo de Funcionario: Gerente\n"
            //    << endl;
            posicao = i;
            encontrado = 1;
            break;
        }
    }
    // cout << "encontrado: " << encontrado << endl;
    if (encontrado == 0)
    {
        // cout << "Entrou no for de vendedores" << endl;
        for (int j = 0; j < vendedores.size(); j++)
        {
            string matriculaUser = simplificadorMatricula(this->vendedores[j].getMatricula());
            // cout << matriculaUser << endl;
            // cout << "Matricula: " << matriculaUser << " = " << matriculaString << endl;

            if (matriculaUser == matriculaString)
            {
                //  cout << "Funcionario encontrado!\nTipo de Funcionario: Vendedor\n"
                // << endl;
                posicao = j;
                encontrado = 2;
                break;
            }
        }
    }
    // cout << "encontrado: " << encontrado << endl;
    if (encontrado == 0)
    {
        // cout << "Entrou no for de asg" << endl;

        for (int q = 0; q < asgs.size(); q++)
        {
            string matriculaUser = simplificadorMatricula(this->asgs[q].getMatricula());
            // cout << matriculaUser << endl;
            // cout << "Matricula: " << matriculaUser << " = " << matriculaString << endl;

            if (matriculaUser == matriculaString)
            {
                // cout << "Funcionario encontrado!\nTipo de Funcionario: Asg\n"
                //  << endl;
                posicao = q;
                encontrado = 3;
                break;
            }
        }
    }
    float salario;
    if (encontrado == 0)
        cout << "Funcionario não encontrado no sistema!" << endl;
    if (encontrado == 1)
    {
        Gerente gerente = gerentes[posicao];
        salario = gerente.calcularSalario(0);
        cout << "Nome: " << gerente.getNome();
        cout << " - Matricula: " << gerente.getMatricula();
        cout << " - CPF: " << gerente.getCpf();
        cout << " - Salário: " << salario << endl;
    }
    if (encontrado == 2)
    {
        Vendedor vendedor = vendedores[posicao];
        salario = vendedor.calcularSalario(0);
        cout << "Nome: " << vendedor.getNome();
        cout << " - Matricula: " << vendedor.getMatricula();
        cout << " - Cpf: " << vendedor.getCpf();
        cout << " - Salário: " << salario << endl;
    }
    if (encontrado == 3)
    {
        Asg asg = asgs[posicao];
        salario = asg.calcularSalario(0);
        cout << "Nome: " << asg.getNome();
        cout << " - Matricula: " << asg.getMatricula();
        cout << " - Cpf: " << asg.getCpf();
        cout << " - Salário: " << salario << endl;
    }
};
void Empresa::calcularTodoOsSalarios()
{
    fstream arq;
    cout << "\n";
    arq.open("./Arquivos/relatatorio.txt", ios::out);
    arq << "######### Relatório Financeiro ########\n"
        << endl;

    double total = 0, totalGeral = 0;
    arq << "Cargo:ASG" << endl;
    for (int i = 0; i < asgs.size(); i++)
    {
        arq << asgs[i].getMatricula() << " - " << asgs[i].getNome() << " - R$ " << asgs[i].getSalario() << endl;
        total += stod(asgs[i].getSalario());
        if (i == asgs.size() - 1)
        {
            arq << "Total ASG: R$ " << total << endl;
            totalGeral += total;
            total = 0;
        }
    }
    for (int i = 0; i < vendedores.size(); i++)
    {
        arq << vendedores[i].getMatricula() << " - " << vendedores[i].getNome() << " - R$ " << vendedores[i].getSalario() << endl;
        total += stod(vendedores[i].getSalario());
        if (i == vendedores.size() - 1)
        {
            arq << "Total Vendedores: R$ " << total << endl;
            totalGeral += total;
            total = 0;
        }
    }
    for (int i = 0; i < gerentes.size(); i++)
    {
        arq << gerentes[i].getMatricula() << " - " << gerentes[i].getNome() << " - R$ " << gerentes[i].getSalario() << endl;
        total += stod(gerentes[i].getSalario());
        if (i == gerentes.size() - 1)
        {
            arq << "Total Gerentes: R$ " << total << endl;
            totalGeral += total;
            total = 0;
        }
    }

    arq << "CUSTO TOTAL DE RH: R$ " << totalGeral << endl;
    arq.close();
    arq.open("./Arquivos/relatatorio.txt", ios::in);
    string linha;
    while (getline(arq, linha))
        cout << linha << endl;
};
void Empresa::calcularRecisao(int matricula, Data desligamento)
{
    cout << "\nCalcular Recisão\nMatricula:" << matricula << endl;
    int encontrado = 0;
    int posicao = 0;
    for (int i = 0; i < gerentes.size(); i++)
    {
        string matriculaN = simplificadorMatricula(this->gerentes[i].getMatricula());

        if (stoi(matriculaN) == matricula)
        {
            cout << "\nTipo de Funcionario: Gerente\n"
                 << endl;
            posicao = i;
            encontrado = 1;
        }
    }
    if (encontrado == 0)
    {
        for (int j = 0; j < vendedores.size(); j++)
        {
            string matriculaN = simplificadorMatricula(this->vendedores[j].getMatricula());

            if (stoi(matriculaN) == matricula)
            {
                cout << "\nTipo de Funcionario: Vendedor\n"
                     << endl;
                posicao = j;
                encontrado = 2;
                break;
            }
        }
    }
    if (encontrado == 0)
    {
        for (int q = 0; q < asgs.size(); q++)
        {
            string matriculaN = simplificadorMatricula(this->asgs[q].getMatricula());

            if (stoi(matriculaN) == matricula)
            {
                cout << "\nTipo de Funcionario: Asg\n"
                     << endl;
                posicao = q;
                encontrado = 3;
                break;
            }
        }
    }

    float salario;
    if (encontrado == 0)
        cout << "Funcionario não encontrado no sistema!" << endl;
    if (encontrado == 1)
    {
        salario = gerentes[posicao].calcularRecisao(desligamento);
        cout << "Nome: " << gerentes[posicao].getNome() << "\nMatricula: " << gerentes[posicao].getMatricula();
        cout << "\nCpf: " << gerentes[posicao].getCpf() << "\nData Ingresso: " << gerentes[posicao].getIngressoEmpresa().dia << "/" << gerentes[posicao].getIngressoEmpresa().mes << "/" << gerentes[posicao].getIngressoEmpresa().ano;
        cout << "\nData saida:" << desligamento.dia << "/" << desligamento.mes << "/" << desligamento.ano << "\nRecisão: " << salario << endl;
    }
    if (encontrado == 2)
    {
        salario = vendedores[posicao].calcularRecisao(desligamento);
        cout << "Nome: " << vendedores[posicao].getNome() << "\nMatricula: " << vendedores[posicao].getMatricula();
        cout << "\nCpf: " << vendedores[posicao].getCpf() << "\nData Ingresso: " << vendedores[posicao].getIngressoEmpresa().dia << "/" << vendedores[posicao].getIngressoEmpresa().mes << "/" << vendedores[posicao].getIngressoEmpresa().ano;
        cout << "\nData saida:" << desligamento.dia << "/" << desligamento.mes << "/" << desligamento.ano << "\nRecisão: " << salario << endl;
    }
    if (encontrado == 3)
    {

        salario = asgs[posicao].calcularRecisao(desligamento);
        cout << "Nome: " << asgs[posicao].getNome() << "\nMatricula: " << asgs[posicao].getMatricula();
        cout << "\nCpf: " << asgs[posicao].getCpf() << "\nData Ingresso: " << asgs[posicao].getIngressoEmpresa().dia << "/" << asgs[posicao].getIngressoEmpresa().mes << "/" << asgs[posicao].getIngressoEmpresa().ano;
        cout << "\nData saida:" << desligamento.dia << "/" << desligamento.mes << "/" << desligamento.ano << "\nRecisão: " << salario << endl;
    }
};
