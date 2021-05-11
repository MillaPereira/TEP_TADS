#ifndef RACIONAIS_H
#define RACIONAIS_H

typedef struct Racional_st *Racional_pt;

long int MDC(long int a, long int b);

void simplificaRacional(Racional_pt valor);

Racional_pt criaNumRacional(long int numerador, long int denominador);

long int retornaDen(Racional_pt numero);

long int retornaNum(Racional_pt numero);

void destroiRacional(Racional_pt numRacional);

void imprimeRacional(Racional_pt racional);

void atribuiNovoValorNum(Racional_pt numRacional, long int novoNum);

void atribuiNovoValorDen(Racional_pt numRacional, long int novoDen);

void atribuiNovoValor(Racional_pt numRacional, long int novoNum, long int novoDen);

void copiaNumRacional(Racional_pt num1, Racional_pt num2);

double converteRacionalEmReal(Racional_pt numRacional);

Racional_pt converteRealEmRacional(double numReal);

int comparaNumeros(Racional_pt valor1, Racional_pt valor2);

int verificaEquivalente(Racional_pt valor1, Racional_pt valor2);

int verificaDenominadorZero(Racional_pt numRacional);

int verificaNumeradorZero(Racional_pt numRacional);

int verificaAmbosZero(Racional_pt numRacional);

Racional_pt somaRacionais(Racional_pt valor1, Racional_pt valor2);

void acumulaRacionalSomando(Racional_pt valor1, Racional_pt valor2);

Racional_pt subtraiRacionais(Racional_pt valor1, Racional_pt valor2);

Racional_pt multiplicaRacionais(Racional_pt valor1, Racional_pt valor2);

void acumulaRacionaisMultiplicando(Racional_pt valor1, Racional_pt valor2);

Racional_pt divideRacionais(Racional_pt valor1, Racional_pt valor2);

Racional_pt elevaAoQuadrado(Racional_pt valor);

double raizQuadrada(Racional_pt numRacional);

int verificaRacionalConverteEmInteiro(Racional_pt numRacional);

#endif