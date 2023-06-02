#ifndef ASG_HEADER
#define ASG_HEADER

#include "./Pessoa/pessoa.hpp"
#include "./Funcionario/funcionario.hpp"

class Asg : public Funcionario, public Pessoa
{

     float adicionalInsalubridade;

public:
     Asg();
     Asg(std::string nome, std::string cpf, int diaN, int mesN, int anoN, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quantFilhos,
         float adicionalInsalubridade, std::string salario, std::string matricula, int dia, int mes, int ano);
     float getAdicionalInsalubridade();
     void setAdicionalInsalubridade(float adicionalInsalubridade);
     float calcularSalario(int diasFaltas);
     float calcularRecisao(Data desligamento);
};

#endif