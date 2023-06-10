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
int sorteioN(int minimo, int maximo)
{
    unsigned seed = time(0);
    srand(seed);
    int numero = (minimo + (rand() % maximo));

    cout << "numero sorteado função: " << numero << endl;
    return numero;
}
string Empresa::escolherFuncionario()
{
    int numero = sorteioN(0, 4);
    cout << "primeiro numero sorteado:" << numero << endl;
    string matricula = "289384289";
    if (numero == 0)
    {
        cout << "tamanho: " << asgs.size() << endl;

        numero = sorteioN(0, asgs.size());
        cout << "Entrou no if 0 matricula " << matricula << "numero  " << numero << endl;
        matricula = asgs[numero].getMatricula();
        cout << "Entrou no if 0 matricula " << matricula << "numero  " << numero << endl;
    }
    if (numero == 1)
    {
        cout << "tamanho: " << vendedores.size() << endl;

        numero = sorteioN(0, vendedores.size());
        cout << "Entrou no if 1 matricula " << matricula << "numero  " << numero << endl;
        matricula = vendedores[numero].getMatricula();
        cout << "Entrou no if 1 matricula " << matricula << "numero  " << numero << endl;
    }
    if (numero == 2)
    {
        cout << "tamanho: " << gerentes.size() << endl;

        numero = sorteioN(0, gerentes.size());
        cout << "Entrou no if 2 matricula " << matricula << "numero  " << numero << endl;
        matricula = gerentes[numero].getMatricula();

        cout << "Entrou no if 2 matricula " << matricula << "numero  " << numero << endl;
    }
    cout << "Matricula " << matricula << endl;
    return matricula;
}
void Empresa::carregarFuncoes()
{
    cout << "Entrou em carregar funções" << endl;
    fstream arq;
    arq.open("./Arquivos/funcoes.txt", ios::in);
    string linha;
    vector<string> linhas;
    while (getline(arq, linha))
    {
        cout << linha << endl;
        linhas.push_back(linha);
    }
    for (int i = 0; i < linhas.size(); i++)
    {
        cout << linhas[i] << endl;
        if (linhas[i] == "carregarEmpresa()")
            carregarEmpresa(this->hoje.dia, this->hoje.mes, this->hoje.ano);
        if (linhas[i] == "carregarAsg()")
            carregarAsg();
        if (linhas[i] == "carregarVendedore()")
            carregarVendedor();
        if (linhas[i] == "carregarGerente()")
            carregarGerente();
        if (linhas[i] == "carregaDono()")
            carregarDono();
        if (linhas[i] == "buscaFuncionario()")
        {

            string matricula = escolherFuncionario();
            buscaFuncionario(stoi(matricula));
            i++;
        }
        if (linhas[i] == "calculaSalarioFuncionario()")
        {
            string matricula = escolherFuncionario();
            cacularSalarioFuncionario(stoi(matricula));
            i++;
        }
        if (linhas[i] == "calculaTodosOsSalarios()")
            calcularTodoOsSalarios();
        if (linhas[i] == "calcularRecisao()")
        {
            string matricula = escolherFuncionario();
            Data data;
            data.dia = sorteioN(1, 31);
            data.mes = sorteioN(1, 13);
            data.ano = 2023;
            calcularRecisao(stoi(matricula), data);
            break;
        }
    }
};
void Empresa::carregarEmpresa(int dia, int mes, int ano)
{
    cout << "Carregou empresa" << endl;
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
    cout << "Entrou em carregar ASG\n"
         << endl;
    fstream arq;
    arq.open("./Arquivos/asg.txt", ios::in);
    string linha;
    int contador = 0, posicao = 0;
    vector<string> palavras;
    while (getline(arq, linha))
    {
        cout << "Contador: " << contador << "Linha: " << linha << endl;
        if (contador == 25)
        {
            contador = 0;
            Asg asg(palavras[0], palavras[1], stoi(palavras[11]), stoi(palavras[10]),
                    stoi(palavras[9]), palavras[4], palavras[6], palavras[7],
                    palavras[5], stoi(palavras[8]), stoi(palavras[2]), stoi(palavras[14]),
                    palavras[13], palavras[12], stoi(palavras[17]), stoi(palavras[16]),
                    stoi(palavras[15]));
            cout << "Criou asg" << endl;
            this->asgs.push_back(asg);
            posicao++;
        }

        if (contador != 21 && contador != 17 && contador != 13 && contador != 7 && contador > 2)
            palavras.push_back(linha);
        contador++;
    }
    cout << "Saiu de Asg" << endl;
};
void Empresa::carregarVendedor()
{
    fstream arq;
    arq.open("./Arquivos/vendedor.txt", ios::in);
    string linha;
    int contador = 0, posicao = 0;
    vector<string> palavras;
    char tipoVendedor;
    while (getline(arq, linha))
    {
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
            this->vendedores[posicao] = vendedor;

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
    int contador = 0, posicao = 0;
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
                            stoi(palavras[17]), stoi(palavras[16]), stof(palavras[15]));
            this->gerentes.push_back(gerente);
            posicao++;
        }
        if (contador != 21 && contador != 17 && contador != 13 && contador != 7 && contador > 2)
            palavras.push_back(linha);
        contador++;
    }
};
void Empresa::carregarDono()
{
    cout << "Entrou em carregar dono" << endl;

    fstream arq;
    arq.open("./Arquivos/dono.txt", ios::in);
    string linha;
    int contador = 0;
    vector<string> palavras;
    while (getline(arq, linha))
    {
        cout << linha << endl;
        if (contador == 14)
        {
            contador = 0;
        }
        if (contador >= 3)
        {
            palavras.push_back(linha);
        }
        contador++;
    }
    try
    {
        Pessoa donoF(palavras[0], palavras[1], stoi(palavras[11]), stoi(palavras[10]), stoi(palavras[9]), palavras[3], palavras[4], palavras[6], palavras[7], palavras[5], stoi(palavras[8]), stoi(palavras[2]));
        this->dono = donoF;
    }
    catch (const std::exception &e)
    {
        cout << "Em carregar dono: ";
        std::cerr << e.what() << '\n';
    }
};
void Empresa::imprimeAsgs()
{
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
    Pessoa funcionario;
    bool encontrado = false;
    for (int i = 0; i < gerentes.size(); i++)
    {
        if (stoi(this->gerentes[i].getMatricula()) == matricula)
        {
            cout << "Funcionario encontrado!\nTipo de Funcionario: Gerente\n"
                 << endl;
            funcionario = this->gerentes[i];
            encontrado = true;
        }
    }
    for (int j = 0; j < vendedores.size(); j++)
    {
        if (stoi(this->vendedores[j].getMatricula()) == matricula)
        {
            cout << "Funcionario encontrado!\nTipo de Funcionario: Vendedor\n"
                 << endl;
            funcionario = this->vendedores[j];
            encontrado = true;
        }
    }
    for (int q = 0; q < asgs.size(); q++)
    {
        if (stoi(this->asgs[q].getMatricula()) == matricula)
        {
            cout << "Funcionario encontrado!\nTipo de Funcionario: Asg\n"
                 << endl;
            funcionario = this->asgs[q];
            encontrado = true;
        }
    }
    if (encontrado == false)
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

    bool encontrado = 0;
    string matriculaString = to_string(matricula);
    int posicao = 0;
    for (int i = 0; i < gerentes.size(); i++)
    {
        if (this->gerentes[i].getMatricula() == matriculaString)
        {
            cout << "Funcionario encontrado!\nTipo de Funcionario: Gerente\n"
                 << endl;
            posicao = i;
            encontrado = 1;
        }
    }
    if (encontrado == 0)
    {
        for (int j = 0; j < vendedores.size(); j++)
        {
            if (this->vendedores[j].getMatricula() == matriculaString)
            {
                cout << "Funcionario encontrado!\nTipo de Funcionario: Vendedor\n"
                     << endl;
                posicao = j;
                encontrado = 2;
            }
        }
    }
    if (encontrado == 0)
    {
        for (int q = 0; q < asgs.size(); q++)
        {
            if (this->asgs[q].getMatricula() == matriculaString)
            {
                cout << "Funcionario encontrado!\nTipo de Funcionario: Asg\n"
                     << endl;
                posicao = q;
                encontrado = 3;
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
    }
    if (encontrado == 2)
    {
        Vendedor vendedor = vendedores[posicao];
        salario = vendedor.calcularSalario(0);
    }
    if (encontrado == 3)
    {
        Asg asg = asgs[posicao];
        salario = asg.calcularSalario(0);
    }
};
void Empresa::calcularTodoOsSalarios()
{
    fstream arq;
    arq.open("relatatorio.txt", ios::out);
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
    arq.open("Arquivos/relatatorio.txt", ios::in);
    string linha;
    while (getline(arq, linha))
        cout << linha << endl;
};
void Empresa::calcularRecisao(int matricula, Data desligamento)
{
    bool encontrado = 0;
    int posicao = 0;
    for (int i = 0; i < gerentes.size(); i++)
    {
        if (stoi(this->gerentes[i].getMatricula()) == matricula)
        {
            cout << "Funcionario encontrado!\nTipo de Funcionario: Gerente\n"
                 << endl;
            posicao = i;
            encontrado = 1;
        }
    }
    if (encontrado == 0)
    {
        for (int j = 0; j < vendedores.size(); j++)
        {
            if (stoi(this->vendedores[j].getMatricula()) == matricula)
            {
                cout << "Funcionario encontrado!\nTipo de Funcionario: Vendedor\n"
                     << endl;
                posicao = j;
                encontrado = 2;
            }
        }
    }
    if (encontrado == 0)
    {
        for (int q = 0; q < asgs.size(); q++)
        {
            if (stoi(this->asgs[q].getMatricula()) == matricula)
            {
                cout << "Funcionario encontrado!\nTipo de Funcionario: Asg\n"
                     << endl;
                posicao = q;
                encontrado = 3;
            }
        }
    }
    float salario;
    if (encontrado == 0)
        cout << "Funcionario não encontrado no sistema!" << endl;
    if (encontrado == 1)
    {
        Gerente gerente = gerentes[posicao];
        salario = gerente.calcularRecisao(desligamento);
    }
    if (encontrado == 2)
    {
        Vendedor vendedor = vendedores[posicao];
        salario = vendedor.calcularRecisao(desligamento);
    }
    if (encontrado == 3)
    {
        Asg asg = asgs[posicao];
        salario = asg.calcularRecisao(desligamento);
    }
};
