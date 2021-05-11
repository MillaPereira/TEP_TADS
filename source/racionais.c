#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "racionais.h"
#define eps 0.00001

typedef struct Racional_st{
    long int num;
    long int den;
} Racional_t;

typedef struct Racional_st Racional_t;

Racional_pt criaNumRacional(long int numerador, long int denominador){
    Racional_pt numRacional = (Racional_t*) malloc(sizeof(Racional_t));
    if(numRacional == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    numRacional->num = numerador;
    numRacional->den = denominador;
    
    if(verificaDenominadorZero(numRacional) == 1)
        printf("Nao Existe");
    return numRacional;
}

// Funcao calcula MDC
long int MDC(long int a, long int b){
    if(b == 0)
        return a;
    else
        return MDC(b, a%b);   
}

// Funcao para simplificar racional 
void simplificaRacional(Racional_pt valor){
    long int mdc;
    mdc = MDC(valor->num, valor->den);
    valor->num /= mdc;
    valor->den /= mdc;
}

long int retornaDen(Racional_pt numero){
    return numero->den;
}

long int retornaNum(Racional_pt numero){
    return numero->num;
}

void destroiRacional(Racional_pt numRacional){
    free(numRacional);
    numRacional = NULL;
}

void imprimeRacional(Racional_pt racional){
  printf("%ld/%ld\n", retornaNum(racional), retornaDen(racional));
}

void atribuiNovoValorNum(Racional_pt numRacional, long int novoNum){
  numRacional->num = novoNum;
}

void atribuiNovoValorDen(Racional_pt numRacional, long int novoDen){
  numRacional->den = novoDen;
}

void atribuiNovoValor(Racional_pt numRacional, long int novoNum, long int novoDen){
  atribuiNovoValorNum(numRacional, novoNum);
  atribuiNovoValorDen(numRacional, novoDen);
}

void copiaNumRacional(Racional_pt num1, Racional_pt num2){
    num1->num = num2->num;
    num1->den = num2->den;
}

int comparaNumeros(Racional_pt valor1, Racional_pt valor2){
    long double div1, div2;

    div1 = (long double) (valor1->num) / (valor1->den);
    div2 = (long double) (valor2->num) / (valor2->den);

    if(div1 == div2){
        return 0;
    }
    if(div1 < div2){
        return -1;
    }
    return 1;
}

int verificaEquivalente(Racional_pt valor1, Racional_pt valor2){
    long double div1, div2;

    div1 = (long double) (valor1->num) / (valor1->den);
    div2 = (long double) (valor2->num) / (valor2->den);

    if(div1 == div2)
        return 1;
    else
        return 0;
}

int verificaDenominadorZero(Racional_pt numRacional){
    if(numRacional->den == 0)
        return 1;
    else
        return 0;
}

int verificaNumeradorZero(Racional_pt numRacional){
    if(numRacional->num == 0)
        return 1;
    else
        return 0;
}
    
int verificaAmbosZero(Racional_pt numRacional){
    if(numRacional->num == 0 && numRacional->den == 0)
        return 1;
    else
        return 0;
}

Racional_pt somaRacionais(Racional_pt valor1, Racional_pt valor2){
    Racional_pt resultado;
    resultado = criaNumRacional(0, 1);

    resultado->num = (valor1->num * valor2->den) + (valor1->den * valor2->num);
    resultado->den = (valor1->den * valor2->den);
    
    // simplificando resultado 
    simplificaRacional(resultado);
    return resultado;
}

void acumulaRacional(Racional_pt valor1, Racional_pt valor2){

    valor1->num = (valor1->num * valor2->den) + (valor1->den * valor2->num);
    valor1->den = (valor1->den * valor2->den);

    // simplificando o resultado 
    simplificaRacional(valor1);
}

Racional_pt subtraiRacionais(Racional_pt valor1, Racional_pt valor2){
    Racional_pt resultado;
    resultado = criaNumRacional(0, 1);

    resultado->num = (valor1->num * valor2->den) - (valor1->den * valor2->num);
    resultado->den = (valor1->den * valor2->den);

    // simplificando o resultado 
    simplificaRacional(resultado);
    return resultado;
}

Racional_pt multiplicaRacionais(Racional_pt valor1, Racional_pt valor2){
    Racional_pt resultado;
    resultado = criaNumRacional(0, 1);

    resultado->num = (valor1->num * valor2->num);
    resultado->den = (valor1->den * valor2->den);

    // simplificando o resultado 
    simplificaRacional(resultado);
    return resultado;
}

void acumulaMultiplicacaoRacionais(Racional_pt valor1, Racional_pt valor2){
    valor1->num *= valor2->num;
    valor1->den *= valor2->den;
    
    //simplificando resultado 
    simplificaRacional(valor1);
}

Racional_pt divideRacionais(Racional_pt valor1, Racional_pt valor2){
    Racional_pt resultado;
    resultado = criaNumRacional(0, 1);

    resultado->num = (valor1->num * valor2->den);
    resultado->den = (valor1->den * valor2->num);

    // simplificando resultado
    simplificaRacional(resultado);
    return resultado;
}

Racional_pt elevaAoQuadrado(Racional_pt valor){
    Racional_pt resultado = multiplicaRacionais(valor, valor);
    // simplificando resultado 
    simplificaRacional(resultado);
    return resultado;
    return multiplicaRacionais(valor, valor);
}

double raizQuadrada(Racional_pt numRacional){
    double real = (double) numRacional->num / numRacional->den;
    double Xn, X = 1.0;
    for(int i = 1; i <= 10; i++){
        Xn = (X + real / X) / 2;
        if(fabs(X - Xn) < eps){
           break;
        }
        X = Xn;
    }
    return X;
}

double converteRacionalEmReal(Racional_pt numRacional){
    double numReal;
    double numerador = numRacional->num;
    double denominador = numRacional->den;
    numReal = numerador / denominador;
    return numReal;
}

// verificar se eh isso mesmo 
Racional_pt converteRealEmRacional(double numReal){
    Racional_pt numRacional;
    numRacional = criaNumRacional(numReal*1000000, 1000000);
    simplificaRacional(numRacional);
    
    return numRacional;  
}

int verificaRacionalConverteEmInteiro(Racional_pt numRacional){
    long double numero;
    numero = numRacional->num / numRacional->den;
    if((numero - ((int)numero)) < eps)
        return 1;
    else
        return 0;
}

