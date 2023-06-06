#include <iostream>
#include "Empresa/empresa.hpp"
#include "util.hpp"

int main(int argc, char const *argv[])
{
    Data DataHoje(stoi(argv[0]), stoi(argv[1]), stoi(argv[2]));
    Empresa *atacadoDosCalcado = new Empresa("Atacado dos Calçados", "40.101.588/0001-98", 156289.56, DataHoje);
    atacadoDosCalcado->carregarFuncoes();
    return 0;
}
