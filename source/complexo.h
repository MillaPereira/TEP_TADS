#ifndef COMPLEXO_H
#define COMPLEXO_H

/*Definicao do ponteiro para complexo*/
typedef struct TIPADO_(Complexo_st) * TIPADO_(Complexo_pt);

TIPADO_(Complexo_pt) TIPADO_(criaComplexo)(TIPO_ numReal, TIPO_ numImag);

void TIPADO_(destroiComplexo) (TIPADO_(Complexo_pt) numComplexo);

TIPO_ TIPADO_(retornaReal) (TIPADO_(Complexo_pt) numComplexo);

TIPO_ TIPADO_(retornaImaginario) (TIPADO_(Complexo_pt) numComplexo);

void TIPADO_(imprimeComplexo)(TIPADO_(Complexo_pt) numComplexo);

void TIPADO_(atribuiComplexo) (TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2);

TIPADO_(Complexo_pt) TIPADO_(copiaComplexo)(TIPADO_(Complexo_pt) numero);

double TIPADO_(retornaMagnitude) (TIPADO_(Complexo_pt) numComplexo); 

double TIPADO_(retornaFase) (TIPADO_(Complexo_pt) numComplexo);

int TIPADO_(verificaModuloZero) (TIPADO_(Complexo_pt) numComplexo);

int TIPADO_(verificaApenasReal) (TIPADO_(Complexo_pt) numComplexo);

int TIPADO_(verificaApenasImaginario)(TIPADO_(Complexo_pt) numComplexo);

int TIPADO_(comparaComplexos)(TIPADO_(Complexo_pt) complexo1, TIPADO_(Complexo_pt) complexo2);

int TIPADO_(comparaModuloNumeros) (TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2);

int TIPADO_(comparaAngulosNumeros)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2);

void TIPADO_(atribuiNovoValorReal)(TIPADO_(Complexo_pt) numComplexo, TIPO_ novoValor);

void TIPADO_(atribuiNovoValorImaginario)(TIPADO_(Complexo_pt) numComplexo, TIPO_ novoValor);

void TIPADO_(atribuiNovoValorModulo)(TIPADO_(Complexo_pt) numComplexo, double novoModulo);

void TIPADO_(atribuiNovoValorAngulo)(TIPADO_(Complexo_pt) numComplexo, double novoAngulo);

TIPADO_(Complexo_pt) TIPADO_(retornaConjugado)(TIPADO_(Complexo_pt) numComplexo);

TIPADO_(Complexo_pt) TIPADO_(somaComplexo)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2);
 
TIPADO_(Complexo_pt) TIPADO_(subtraiComplexo)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2);

TIPADO_(Complexo_pt) TIPADO_(divideComplexo)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2);

TIPADO_(Complexo_pt) TIPADO_(multiplicaComplexo)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2);

void TIPADO_(acumulaSomando)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2);

void TIPADO_(acumulaMultiplicando)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2);

TIPADO_(Complexo_pt) TIPADO_(operacaoComplexo)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2, char *operacao);

#endif