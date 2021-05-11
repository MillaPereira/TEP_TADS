#ifndef VETOR_H
#define VETOR_H

typedef struct TIPADO_(Vetor_st) * TIPADO_(Vetor_pt);

void TIPADO_(realocaEspaco)(TIPADO_(Vetor_pt) vetor);

void TIPADO_(atribuiElemento)(TIPADO_(Vetor_pt) vetor, int i, TIPO2_ real, TIPO2_ imag);

TIPADO2_(Complexo_pt) TIPADO_(retornaComplexo)(TIPADO_(Vetor_pt) vetor, int i);

TIPADO_(Vetor_pt) TIPADO_(criaVetor)(int n);

void TIPADO_(destroiVetor)(TIPADO_(Vetor_pt) vetor);

TIPO2_ TIPADO_(retornaElementoReal)(TIPADO_(Vetor_pt) vetor, int indice);

TIPO2_ TIPADO_(retornaElementoImag)(TIPADO_(Vetor_pt) vetor, int indice);

void TIPADO_(atribuiVetor)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2);

TIPADO_(Vetor_pt) TIPADO_(criaCopiaVetor)(TIPADO_(Vetor_pt) vetor);

int TIPADO_(retornaNumeroAtualElementos)(TIPADO_(Vetor_pt) vetor);

void TIPADO_(imprimeVetor)(TIPADO_(Vetor_pt) vetor);

int TIPADO_(retornaNumeroMaxElementos)(TIPADO_(Vetor_pt) vetor);

int TIPADO_(retornaIndice)(TIPADO_(Vetor_pt) vetor);

TIPO_ TIPADO_(retornaPrimeiroElemento)(TIPADO_(Vetor_pt) vetor);

TIPO_ TIPADO_(retornaProximoElemento)(TIPADO_(Vetor_pt) vetor, int indice);

TIPO_ TIPADO_(retornaElementoAnterior)(TIPADO_(Vetor_pt) vetor, int indice);

TIPO_ TIPADO_(retornaUltimoElemento)(TIPADO_(Vetor_pt) vetor);

TIPO_ TIPADO_(retornaElementoDePosicaoI)(TIPADO_(Vetor_pt) vetor, int indice);

void TIPADO_(atribuirValorNaIesimaPosicao)(TIPADO_(Vetor_pt) vetor, int indice, TIPADO2_(Complexo_pt) valor);  

void TIPADO_(adicionaElemento)(TIPADO_(Vetor_pt) vetor, TIPADO2_(Complexo_pt) novoElemento);

void TIPADO_(eliminaElementoDePosicaoI)(TIPADO_(Vetor_pt) vetor, int indice); 

void TIPADO_(eliminaTodosElementos)(TIPADO_(Vetor_pt) vetor);

double TIPADO_(valorDeMaiorModulo)(TIPADO_(Vetor_pt) vetor);

double TIPADO_(valorDeMenorModulo)(TIPADO_(Vetor_pt) vetor);

int TIPADO_(quantElementosDeValorV)(TIPADO_(Vetor_pt) vetor, TIPADO2_(Complexo_pt) valor);

int *TIPADO_(retornaVetorComPosicoesQueTemV)(TIPADO_(Vetor_pt) vetor, TIPADO2_(Complexo_pt) valor);

int TIPADO_(criterioOrdenacao) (const void * a, const void * b);

void TIPADO_(ordenarVetor)(TIPADO_(Vetor_pt) vetor);

TIPADO_(Vetor_pt) TIPADO_(intercalaVetor)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2);

TIPADO_(Vetor_pt) TIPADO_(somaVetores)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2);

TIPO_ TIPADO_(produtoInternoVetores) (TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2);

TIPADO_(Vetor_pt) TIPADO_(subtraiVetores)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2);

void TIPADO_(multiplicaVetorPorEscalar)(TIPADO_(Vetor_pt) vetor, double escalar); 

void TIPADO_(acumulaVetor) (TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2);

double TIPADO_(mediaAritimetica) (TIPADO_(Vetor_pt) vetor);

double TIPADO_(varianciaVetor) (TIPADO_(Vetor_pt) vetor);

double TIPADO_(desvioPadrao) (TIPADO_(Vetor_pt) vetor);

double TIPADO_(medianaVetor) (TIPADO_(Vetor_pt) vetor);

#endif 