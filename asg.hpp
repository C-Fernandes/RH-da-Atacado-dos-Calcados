#ifndef ASG_HEADER
#define ASG_HEADER

#include "pessoa.hpp"
#include "funcionario.hpp"

class Asg : public Funcionario : public Pessoa
{

     float adicionalInsalubridade;
     public:
     Asg();
     Asg(std::string nome, std::string cpf, std::string dataNasciment, std::string estado, std::string cidade, std::string bairro, std::string rua, std::string cep, int numero, int quatFilhos, float adicionalInsalubridade, std::string salario, std::matricula, int dia, int mes, int ano);
};

#endif