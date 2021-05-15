#ifndef COMPLEXO_RACIONAL_H
#define COMPLEXO_RACIONAL_H
#define eps 0.00001
#include "racionais.h"

typedef struct Racional_st *Racional_pt;
typedef struct R_Complexo_st *R_Complexo_pt;

R_Complexo_pt R_criaComplexo(long int numReal, long int denReal, long int numImag, long int denImag);

void R_destroiComplexo(R_Complexo_pt numComplexo);

void R_imprimeComplexo(R_Complexo_pt numComplexo);

Racional_pt R_retornaReal(R_Complexo_pt numComplexo);

Racional_pt R_retornaImaginario(R_Complexo_pt numComplexo);

void R_atribuiComplexo(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2);

R_Complexo_pt R_copiaComplexo(R_Complexo_pt numComplexo);

double R_retornaMagnitude(R_Complexo_pt numComplexo);

double R_retornaFase(R_Complexo_pt numComplexo);

int R_verificaModuloZero(R_Complexo_pt numComplexo);

int R_verificaApenasReal(R_Complexo_pt numComplexo);

int R_verificaApenasImaginario(R_Complexo_pt numComplexo);

int R_comparaModuloNumeros(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2);

int R_comparaAngulosNumeros(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2);

void R_atribuiNovoValorReal(R_Complexo_pt numComplexo, Racional_pt novoValor);

void R_atribuiNovoValorImaginario(R_Complexo_pt numComplexo, Racional_pt novoValor);

void R_atribuiNovoValorModulo(R_Complexo_pt numComplexo, double novoModulo);

void R_atribuiNovoValorAngulo(R_Complexo_pt numComplexo, double novoAngulo);

R_Complexo_pt R_retornaConjugado(R_Complexo_pt numComplexo);

R_Complexo_pt R_somaComplexo(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2);

R_Complexo_pt R_subtraiComplexo(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2);

R_Complexo_pt R_divideComplexo(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2);

R_Complexo_pt R_multiplicaComplexo(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2);

void R_acumulaSomando(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2);

void R_acumulaMultiplicando(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2);

R_Complexo_pt R_operacaoComplexo(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2, char *operacao);

#endif