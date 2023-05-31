#include "asg.hpp"
#include <iostream>
using namespace std;

float Asg::calcularSalario(int diasFaltas)
{
    string salarioS = getSalario();
    double salario = stod(salarioS);
    double acresFilhos = getQuantFilhos() * 100;
};
float Asg::calcularRecisao(Data desligamento){

};