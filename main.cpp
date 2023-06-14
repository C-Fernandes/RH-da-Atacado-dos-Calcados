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
    Empresa *atacadoDosCalcado = new Empresa("Atacado dos Calçados", "40.101.588/0001-98", 156289.56, dataHoje);
    try
    {
       atacadoDosCalcado->carregarFuncoes();
    }
    catch(int error)
    {
        if(error == 0){cout << "Error ao abrir o arquivo funções." << endl;}
       else{ std::cerr << error << '\n';}
    }
    
    
    return 0;
}
