#ifndef UTIL
#define UTIL
#include <iostream>

typedef struct Data
{
    int ano, mes, dia;
} Data;
typedef struct Endereco
{
    std::string cidade, bairro, rua, cep;
    int numero;
} Endereco;

#endif;