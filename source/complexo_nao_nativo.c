#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <string.h>
#include "complexo_nao_nativo.h"
#include "racionais.h"

typedef struct Racional_st{
    long int num;
    long int den;
} Racional_t;

struct R_Complexo_st{
    Racional_pt real;
    Racional_pt imag;
};

typedef struct R_Complexo_st R_Complexo_t;

R_Complexo_pt R_criaComplexo(long int numReal, long int denReal, long int numImag, long int denImag){
    R_Complexo_pt numComplexo = (R_Complexo_t*) malloc(sizeof(R_Complexo_t));
    if(denReal == 0 || denImag == 0){
        printf("Nao Existe\n");
        exit(1);
    }
    else{
        numComplexo->real = criaNumRacional(numReal, denReal);
        numComplexo->imag = criaNumRacional(numImag, denImag);
    }
    if(numComplexo == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    numComplexo->real = numComplexo->real;
    numComplexo->imag = numComplexo->imag;

    return numComplexo;
}

void R_destroiComplexo(R_Complexo_pt numComplexo){
    destroiRacional(numComplexo->real);
    destroiRacional(numComplexo->imag);
    free(numComplexo);
    numComplexo = NULL;
}

void R_imprimeComplexo(R_Complexo_pt numComplexo){
    printf("%ld/%ld + ", retornaNum(numComplexo->real), retornaDen(numComplexo->real));
    printf("%ld/%ldi\n", retornaNum(numComplexo->imag), retornaDen(numComplexo->imag));
}

Racional_pt R_retornaReal(R_Complexo_pt numComplexo){
    return numComplexo->real;
}

Racional_pt R_retornaImaginario(R_Complexo_pt numComplexo){
    return numComplexo->imag;
}

void R_atribuiComplexo(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2){
    numComplexo1->real = numComplexo2->real;
    numComplexo1->imag = numComplexo2->imag;
}

R_Complexo_pt R_copiaComplexo(R_Complexo_pt numComplexo){
    R_Complexo_pt copia;
    // cria complexo com 1 no denominador 
    copia = R_criaComplexo(0, 1, 0, 1);

    copia->real = numComplexo->real;
    copia->imag = numComplexo->imag;

    return copia;
}

double R_retornaMagnitude(R_Complexo_pt numComplexo){
    double real, imag, modulo;

    real = converteRacionalEmReal(R_retornaReal(numComplexo));
    imag = converteRacionalEmReal(R_retornaImaginario(numComplexo));

    modulo = pow(real, 2) + pow(imag, 2);

    modulo = sqrt(modulo);

    return modulo;
}

double R_retornaFase(R_Complexo_pt numComplexo){
    double angulo, realDouble, imagDouble, magDouble;
    Racional_pt real, imag;
    real = R_retornaReal(numComplexo);
    imag = R_retornaImaginario(numComplexo);
    magDouble = R_retornaMagnitude(numComplexo); 

    if (retornaNum(real)== 0){
      if (retornaNum(imag) > 0){
        return 3.14159265359/2;
      }
      else if (retornaNum(imag) < 0){
        return -3.14159265359/2;
      }
      else{
        return 0;
      }
    }
    imagDouble = converteRacionalEmReal(imag);

    angulo = asin(imagDouble / magDouble);
    
    if (retornaNum(imag) == 0){
      return 3.141592;
    }
    if (retornaNum(imag) >= 0 && retornaNum(real) < 0){
      angulo = angulo + 3.141592/2;
    }
    if (retornaNum(imag) <= 0 && retornaNum(real) < 0){
      angulo = angulo - 3.141592/2;
    }  

    return angulo;
}

int R_verificaModuloZero(R_Complexo_pt numComplexo){  
    double modulo = R_retornaMagnitude(numComplexo);

    if(modulo <= eps)
        return 1;
    else 
        return 0;
}

int R_verificaApenasReal(R_Complexo_pt numComplexo){
    Racional_pt real, imag;
    real = R_retornaReal(numComplexo);
    imag = R_retornaImaginario(numComplexo);

    if((retornaNum(imag)/retornaDen(imag)) <= eps)
        return 1;
    else 
        return 0;
}

int R_verificaApenasImaginario(R_Complexo_pt numComplexo){
    Racional_pt real, imag;
    real = R_retornaReal(numComplexo);
    imag  = R_retornaImaginario(numComplexo);

    if((retornaNum(real)/retornaDen(real)) <= eps)
        return 1;
    else
        return 0;
}

int R_comparaModuloNumeros(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2){
    double modulo1, modulo2;
    modulo1 = R_retornaMagnitude(numComplexo1);
    modulo2 = R_retornaMagnitude(numComplexo2);

    if(fabsl(modulo1 - modulo2) > eps){
        if(modulo1 < modulo2)
            return -1;
        if(modulo1 > modulo2)
            return 1;
    }
    return 0;
}

int R_comparaAngulosNumeros(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2){
    long double angulo1, angulo2;

    angulo1 = R_retornaFase(numComplexo1);
    angulo2 = R_retornaFase(numComplexo2); 

    printf("%Lf\n", angulo1);
    printf("%Lf\n", angulo2);
    if(fabsl((angulo1 - angulo2)) > eps){
        if(angulo1 < angulo2)
            return -1;
        if(angulo1 > angulo2)
            return 1;
    }
    return 0;
}

void R_atribuiNovoValorReal(R_Complexo_pt numComplexo, Racional_pt novoValor){
    copiaNumRacional(R_retornaReal(numComplexo), novoValor);
}

void R_atribuiNovoValorImaginario(R_Complexo_pt numComplexo, Racional_pt novoValor){
    copiaNumRacional(R_retornaImaginario(numComplexo), novoValor);
}

void R_atribuiNovoValorModulo(R_Complexo_pt numComplexo, double novoModulo){
    double angulo, real, imag; 
    angulo = R_retornaFase(numComplexo);
    real = novoModulo * cos(angulo);
    imag = novoModulo * sin(angulo);

    R_atribuiNovoValorReal(numComplexo, converteRealEmRacional(real));
    R_atribuiNovoValorImaginario(numComplexo, converteRealEmRacional(imag));
}


void R_atribuiNovoValorAngulo(R_Complexo_pt numComplexo, double novoAngulo){
    double modulo, real, imag;
    modulo = R_retornaMagnitude(numComplexo);
    real = modulo * cos(novoAngulo);
    imag = modulo * sin(novoAngulo);
    printf ("%f %f\n", real, imag);

    Racional_pt realR, imagR;
    realR = converteRealEmRacional(real);

    imprimeRacional(realR);

    imagR = converteRealEmRacional(imag);
    
    R_atribuiNovoValorReal(numComplexo, realR);

    R_atribuiNovoValorImaginario(numComplexo, imagR);
}

R_Complexo_pt R_retornaConjugado(R_Complexo_pt numComplexo){
    R_Complexo_pt conjugado;

    R_atribuiComplexo(conjugado, numComplexo);
    
    atribuiNovoValorNum(R_retornaImaginario(conjugado), retornaNum(conjugado->imag)*(-1));
    
    return conjugado;
}

R_Complexo_pt R_somaComplexo(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2){
    R_Complexo_pt resultado;
    resultado = R_criaComplexo(0, 1, 0, 1);
   
    resultado->real = somaRacionais(numComplexo1->real, numComplexo2->real);
    resultado->imag = somaRacionais(numComplexo1->imag, numComplexo2->imag);

    return resultado;
}

R_Complexo_pt R_subtraiComplexo(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2){
    R_Complexo_pt resultado;
    resultado = R_criaComplexo(0, 1, 0, 1);
    
    resultado->real = subtraiRacionais(numComplexo1->real, numComplexo2->real);
    resultado->imag = subtraiRacionais(numComplexo1->imag, numComplexo2->imag);

    return resultado;
}

R_Complexo_pt R_divideComplexo(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2){
    R_Complexo_pt resultado;
    resultado = R_criaComplexo(0, 1, 0, 1);
    Racional_pt denominador;
    
    resultado->real = subtraiRacionais(multiplicaRacionais(numComplexo1->real, numComplexo2->real), multiplicaRacionais(numComplexo1->imag, numComplexo2->imag));
    resultado->imag = somaRacionais(multiplicaRacionais(numComplexo1->real, numComplexo2->imag), multiplicaRacionais(numComplexo1->imag, numComplexo2->real));

    denominador = somaRacionais(multiplicaRacionais(numComplexo2->real, numComplexo2->real), multiplicaRacionais(numComplexo2->imag, numComplexo2->imag));
    
    if(verificaNumeradorZero(denominador) == 1){
        printf("Nao e possivel realizar a divisao\n");
        exit(1);
    }

    resultado->real = divideRacionais(resultado->real, denominador);
    resultado->imag = divideRacionais(resultado->imag, denominador);

    return resultado;
}

R_Complexo_pt R_multiplicaComplexo(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2){
    R_Complexo_pt resultado;
    resultado = R_criaComplexo(0, 1, 0, 1);

    if(resultado == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    
    resultado->real = subtraiRacionais(multiplicaRacionais(numComplexo1->real, numComplexo2->real), multiplicaRacionais(numComplexo1->imag, numComplexo2->imag));
    resultado->imag = somaRacionais(multiplicaRacionais(numComplexo1->real, numComplexo2->imag), multiplicaRacionais(numComplexo1->imag, numComplexo2->real));

    return resultado;
}

void R_acumulaSomando(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2){
    numComplexo1->real = somaRacionais(numComplexo1->real, numComplexo2->real);
    numComplexo1->imag = somaRacionais(numComplexo1->imag, numComplexo2->imag);
}

void R_acumulaMultiplicando(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2){
    Racional_pt real1, imag1, real2, imag2, copiaReal1, copiaImag1;
    real1 = R_retornaReal(numComplexo1);
    imag1 = R_retornaImaginario(numComplexo1);
    real2 = R_retornaReal(numComplexo2);
    imag2 = R_retornaImaginario(numComplexo2);
    copiaReal1 = real1;
    copiaImag1 = imag1;

    numComplexo1->real = subtraiRacionais(multiplicaRacionais(numComplexo1->real, numComplexo2->real), multiplicaRacionais(numComplexo1->imag, numComplexo2->imag));
    somaRacionais(multiplicaRacionais(copiaReal1, numComplexo2->imag), multiplicaRacionais(copiaImag1, numComplexo2->real));
}

R_Complexo_pt R_operacaoComplexo(R_Complexo_pt numComplexo1, R_Complexo_pt numComplexo2, char *operacao) {
    if (strcmp(operacao, "+") == 0){
      return R_somaComplexo(numComplexo1, numComplexo2);
    }
    else if (strcmp(operacao, "-") == 0){
      return R_subtraiComplexo(numComplexo1, numComplexo2);
    }
    else if (strcmp(operacao, "*") == 0){
      return R_multiplicaComplexo(numComplexo1, numComplexo2);
    }
    else if (strcmp(operacao, "/") == 0){
      return R_divideComplexo(numComplexo1, numComplexo2);
    }
    else if (strcmp(operacao, "+=") == 0){
      R_acumulaSomando(numComplexo1, numComplexo2);
      return numComplexo1;
    }
    else if (strcmp(operacao, "*=") == 0){
      R_acumulaMultiplicando(numComplexo1, numComplexo2);
      return numComplexo1;
    }
    else {
      printf ("Simbolo invalido!\n");
      return NULL;
    }
}
