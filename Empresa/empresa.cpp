#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include "empresa.hpp"

using namespace std;

Empresa::Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal, Data dataHoje) // Construtor parametrizado
{
    this->nomeEmpresa = nomeEmpresa;
    this->cnpj = cnpj;
    this->faturamentoMensal = faturamentoMensal;
    this->hoje.dia = dataHoje.dia;
    this->hoje.mes = dataHoje.mes;
    this->hoje.ano = dataHoje.ano;
};
// Gets e Sets
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

string simplificadorMatricula(string matricula) // Função para tirar ponto e - da matricula
{
    string novaMatricula = "";
    for (int i = 0; i < 8; i++)
    {
        if (matricula[i] != '.' && matricula[i] != '-' && matricula[i] != '\n')
        {
            novaMatricula.push_back(matricula[i]); // Adiciona cada caracter ao final da string
        }
    }
    return novaMatricula;
}
int sorteioN(int minimo, int maximo) // Função para sortear um número aleátorio.
{
    unsigned seed = time(0); // Muda a seed constantemente
    srand(seed);
    return (minimo + (rand() % maximo)); // Pega um valor aleatorio e divide pelo maximo, para obter o resto, somando ao minimo e o retorna.
}
string Empresa::escolherFuncionario() // Função escolher matricula de forma aleatoria
{
    int numero = sorteioN(0, 5);    // Sorteia um numero de 0 a 4
    string matricula = "289384289"; // Caso o número escolhido não seja de 1 a 3
    if (numero == 1)
    {
        numero = sorteioN(0, asgs.size());       // Sorteia de 0 ao numero máximo (tamanho do vector)
        matricula = asgs[numero].getMatricula(); // Pega a matricula e o retorna;
        return matricula;
    }
    if (numero == 2)
    {
        numero = sorteioN(0, vendedores.size());
        matricula = vendedores[numero].getMatricula();
        return matricula;
    }
    if (numero == 3)
    {
        numero = sorteioN(0, gerentes.size());
        matricula = gerentes[numero].getMatricula();
        return matricula;
    }
    else
        return matricula;
}
void Empresa::carregarFuncoes() // Função para carregar funcoes
{
    fstream arq;
    arq.open("./Arquivos/funcoes.txt", ios::in);
    if (!arq.is_open()) // Se o arquivo de funções não for aberto, lança um error
        throw 0;
    string linha;
    while (getline(arq, linha)) // Pega a linha do arquivo e armazena na string linha
    {                           // Compara a linha com cada função e a chama
        if (linha == "carregarEmpresa()")
        {
            try
            {
                carregarEmpresa(this->hoje.dia, this->hoje.mes, this->hoje.ano);
            }
            catch (int error) // Caso o error 0 (defini esse erro para abertura do arquivo) tenha sido lançado
            {
                if (error == 0)
                    cout << "Error ao abrir o arquivo da empresa" << endl;
                else
                    cout << error << endl;
            }
        }

        if (linha == "carregarAsg()")
        {
            try
            {
                carregarAsg();
            }
            catch (int error)
            {
                if (error == 0)
                    cout << "Error ao abrir o arquivo dos vendedores" << endl;
                else
                    cout << error << endl;
            }
        }
        if (linha == "carregarVendedor()")
        {
            try
            {
                carregarVendedor();
            }
            catch (int error)
            {
                if (error == 0)
                    cout << "Error ao abrir o arquivo dos vendedores" << endl;
                else
                    cout << error << endl;
            }
        }
        if (linha == "carregarGerente()")
        {
            try
            {
                carregarGerente();
            }
            catch (int error)
            {
                if (error == 0)
                    cout << "Error ao abrir o arquivo do gerentes" << endl;
                else
                    cout << error << endl;
            }
        };
        if (linha == "carregaDono()")
        {
            try
            {
                carregarDono();
            }
            catch (int error)
            {
                if (error == 0)
                    cout << "Error ao abrir o arquivo do dono" << endl;
                else
                    cout << error << endl;
            }
        };
        if (linha == "imprimeAsgs()")
        {
            try
            {
                imprimeAsgs();
            }
            catch (int error)
            {
                if (error == 0)
                    cout << "Error ao abrir o arquivo dos asgs" << endl;
                else
                    cout << error << endl;
            }
        };
        if (linha == "imprimeVendedores()")
            imprimeVendendores();
        if (linha == "imprimeGerentes()")
            imprimeGerentes();
        if (linha == "imprimeDono()")
            imprimeDono();
        if (linha == "buscaFuncionario()")
        {
            string matricula = escolherFuncionario(); // pega uma matricula aleatoria e depois simplifica
            matricula = simplificadorMatricula(matricula);
            buscaFuncionario(stoi(matricula)); // passa a matricula como inteiro pra função
        }
        if (linha == "calculaSalarioFuncionario()")
        {
            string matricula = escolherFuncionario();
            matricula = simplificadorMatricula(matricula);
            cacularSalarioFuncionario(stoi(matricula));
        }
        if (linha == "calculaTodoOsSalarios()")
        {
            try
            {
                calcularTodoOsSalarios();
            }
            catch (int error)
            { // Como a função escreve e lê no arquivo, é necessário conferir os dois
                if (error == 0)
                    cout << "Error ao abrir o arquivo do relátorio para escrita" << endl;
                if (error == 1)
                    cout << "Error ao abrir o arquivo do relátorio para leitura" << endl;
                else
                    cout << error << endl;
            }
        };
        if (linha == "calcularRecisao()")
        {
            string matricula = escolherFuncionario();
            matricula = simplificadorMatricula(matricula);
            Data data; // Pega números aleatorios para a data
            data.dia = sorteioN(1, 31);
            data.mes = sorteioN(1, 12);
            data.ano = 2023;
            calcularRecisao(stoi(matricula), data);
            break;
        }
    }
};
void Empresa::carregarEmpresa(int dia, int mes, int ano) // Carrega empresa
{
    fstream arq;
    arq.open("./Arquivos/empresa.txt", ios::in);
    if (!arq.is_open())
        throw 0;
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
void Empresa::carregarAsg() // Carrega ASG
{
    fstream arq;
    arq.open("./Arquivos/asg.txt", ios::in);
    if (!arq.is_open())
        throw 0;
    string linha;
    int contador = 0, posicao = 0;
    vector<string> palavras;
    while (getline(arq, linha))
    { // Utiliza o contador como indice para salvar somente as linhas com informações
        if (contador != 21 && contador != 17 && contador != 13 && contador != 7 && contador > 2)
            palavras.push_back(linha); // Salva no vector palavras as linhas com as informações
        contador++;                    // Avança no contador
        if (contador == 25)            // Quando chega no fim do ASG, ele reinicia a contagem para salvar o próximo
        {
            contador = 0;
            Asg asg(palavras[0], palavras[1], stoi(palavras[11]), stoi(palavras[10]),
                    stoi(palavras[9]), palavras[4], palavras[6], palavras[7],
                    palavras[5], stoi(palavras[8]), stoi(palavras[2]), stoi(palavras[14]),
                    palavras[13], palavras[12], stoi(palavras[17]), stoi(palavras[16]),
                    stoi(palavras[15]));
            this->asgs.push_back(asg); // Cria o ASG, adiciona no fim do vector e depois limpa o vector, para armazenar o próximo ASG
            palavras.clear();
        }
    }
};
void Empresa::carregarVendedor() // Funciona da mesma forma do carregar ASG
{
    fstream arq;
    arq.open("./Arquivos/vendedor.txt", ios::in);
    if (!arq.is_open())
        throw 0;
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
void Empresa::carregarGerente() // Funciona da mesma forma do carregar ASG e Vendedor
{
    fstream arq;
    arq.open("./Arquivos/gerente.txt", ios::in);
    if (!arq.is_open())
        throw 0;
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
void Empresa::carregarDono() // Função para carregar dono
{
    fstream arq;
    arq.open("./Arquivos/dono.txt", ios::in);
    if (!arq.is_open())
        throw 0;
    string linha;
    int contador = 0;
    vector<string> palavras;
    while (getline(arq, linha)) // Apenas pega as linhas do arquivo
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
    } // Muda os atributos do Dono
    this->dono.setNome(palavras[0]);
    this->dono.setCpf(palavras[1]);
    this->dono.setEstadoCivil(palavras[3]);
    this->dono.setEnderecoPessoal(palavras[4], palavras[6], palavras[7], palavras[5], stoi(palavras[8]));
    this->dono.setDataNascimento(stoi(palavras[11]), stoi(palavras[10]), stoi(palavras[9]));
    this->dono.setQuantFilhos(stoi(palavras[2]));
};
void Empresa::imprimeAsgs() // Imprime asgs
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
void Empresa::imprimeVendendores() // Imprime Vendendores
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
void Empresa::imprimeGerentes() // Imprime Gerentes
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
void Empresa::imprimeDono() // Imprime Dono
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
void Empresa::buscaFuncionario(int matricula) // Busca Funcionario
{
    cout << "\nBuscar Funcionario\nMatricula:" << matricula << endl; //Informa que entrou na função e a matricula que vai buscar
    Pessoa funcionario;
    bool encontrado = false;
    string matriculaString = to_string(matricula); //Transforma a matricula em String
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
        string matriculaUser = simplificadorMatricula(this->gerentes[i].getMatricula());
        if (matriculaUser == matriculaString)
        {
            posicao = i;
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0)
    {
        for (int j = 0; j < vendedores.size(); j++)
        {
            string matriculaUser = simplificadorMatricula(this->vendedores[j].getMatricula());
            if (matriculaUser == matriculaString)
            {
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
            string matriculaUser = simplificadorMatricula(this->asgs[q].getMatricula());
            if (matriculaUser == matriculaString)
            {
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
    if (!arq.is_open())
        throw 0;
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
    if (!arq.is_open())
        throw 1;
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
