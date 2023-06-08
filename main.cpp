#include <iostream>
#include "Empresa/empresa.hpp"
#include "util.hpp"

using namespace std;
int main(int argc, char const *argv[])
{
    Data dataHoje;
    dataHoje.dia = stoi(argv[0]);
    dataHoje.mes = stoi(argv[1]);
    dataHoje.ano = stoi(argv[2]);
    Empresa *atacadoDosCalcado = new Empresa("Atacado dos Calçados", "40.101.588/0001-98", 156289.56, dataHoje);
    atacadoDosCalcado->carregarFuncoes();
    return 0;
}
