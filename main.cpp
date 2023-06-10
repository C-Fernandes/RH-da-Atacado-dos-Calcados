#include <iostream>
#include "Empresa/empresa.hpp"
#include "util.hpp"

using namespace std;
int main(int argc, char const *argv[])
{
    Data dataHoje;
    try
    {
        dataHoje.dia = stoi(argv[1]);
        dataHoje.mes = stoi(argv[2]);
        dataHoje.ano = stoi(argv[3]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Não foi possivel útilizar a data passada, tente novamente." << '\n';
    }
cout << "Passou aqui" << endl;
    Empresa *atacadoDosCalcado = new Empresa("Atacado dos Calçados", "40.101.588/0001-98", 156289.56, dataHoje);
    atacadoDosCalcado->carregarFuncoes();
    return 0;
}
