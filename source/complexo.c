#ifdef TIPO_
#ifdef TIPADO_
#ifdef FORMATO_

#define eps 0.00001

struct TIPADO_(Complexo_st){
    TIPO_ *real;
    TIPO_ *imag;
};
typedef struct TIPADO_(Complexo_st) TIPADO_(Complexo_t);

TIPADO_(Complexo_pt) TIPADO_(criaComplexo) (TIPO_ numReal, TIPO_ numImag){
    TIPADO_(Complexo_pt) numComplexo = (TIPADO_(Complexo_pt)) malloc(sizeof(TIPADO_(Complexo_t)));
    if(numComplexo == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    numComplexo->real = (TIPO_*) malloc(sizeof(TIPO_));
    numComplexo->imag = (TIPO_*) malloc(sizeof(TIPO_));
    if(numComplexo->real == NULL || numComplexo->imag == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    *(numComplexo)->real = numReal;
    *(numComplexo)->imag = numImag;
    
    return numComplexo;
}

void TIPADO_(destroiComplexo) (TIPADO_(Complexo_pt) numComplexo){
    free(numComplexo->real);
    numComplexo->real = NULL;
    free(numComplexo->imag);
    numComplexo->imag = NULL;
    free(numComplexo);
    numComplexo = NULL;   
}

TIPO_ TIPADO_(retornaReal) (TIPADO_(Complexo_pt) numComplexo){ 
    return *(numComplexo)->real;
}

TIPO_ TIPADO_(retornaImaginario) (TIPADO_(Complexo_pt) numComplexo){
    return *(numComplexo)->imag;
}

void TIPADO_(imprimeComplexo)(TIPADO_(Complexo_pt) numComplexo){
    printf("%.3"FORMATO_" + %.3"FORMATO_"i", TIPADO_(retornaReal)(numComplexo), TIPADO_(retornaImaginario)(numComplexo));
}

void TIPADO_(atribuiComplexo) (TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2){
    numComplexo1->real = numComplexo2->real;
    numComplexo1->imag = numComplexo2->imag;
}

TIPADO_(Complexo_pt) TIPADO_(copiaComplexo)(TIPADO_(Complexo_pt) numero){
    TIPADO_(Complexo_pt) numComplexo;
    numComplexo = TIPADO_(criaComplexo)(0, 0);
    if(numComplexo == NULL){
        printf("Memória insuficiente!\n");
		exit(1);
    }
    numComplexo->real = numero->real;
    numComplexo->imag = numero->imag;

    return numComplexo;
}

double TIPADO_(retornaMagnitude) (TIPADO_(Complexo_pt) numComplexo){
    double modulo, real, imaginario;

    real = *numComplexo->real;
    imaginario = *numComplexo->imag;

    modulo = sqrt(pow(real, 2) + pow(imaginario, 2));

    return fabs(modulo);
}

double TIPADO_(retornaFase) (TIPADO_(Complexo_pt) numComplexo){
    double angulo;

    if (*numComplexo->real == 0){
      if (*numComplexo->imag > 0){
        return 3.14159265359/2;
      }
      else if (*numComplexo->imag < 0){
        return -3.14159265359/2;
      }
      else{
        return 0;
      }
    } 
    angulo = asin(*numComplexo->imag / TIPADO_(retornaMagnitude)(numComplexo));

    if (*numComplexo->imag == 0){
      return 3.141592;
    }
    if (*numComplexo->imag >= 0 && *numComplexo->real < 0){
      angulo = angulo + 3.141592/2;
    }
    if (*numComplexo->imag <= 0 && *numComplexo->real < 0){
      angulo = angulo - 3.141592/2;
    }  

    return angulo;
}

int TIPADO_(verificaModuloZero) (TIPADO_(Complexo_pt) numComplexo){    
    if(TIPADO_(retornaMagnitude)(numComplexo) <= eps)
        return 1;
    else 
        return 0;
}

int TIPADO_(verificaApenasReal) (TIPADO_(Complexo_pt) numComplexo){
    if(*numComplexo->imag <= eps)
        return 1;
    else 
        return 0;
}

int TIPADO_(verificaApenasImaginario)(TIPADO_(Complexo_pt) numComplexo){
    if(*numComplexo->real <= eps)
        return 1;
    else 
        return 0;
}

int TIPADO_(comparaComplexos)(TIPADO_(Complexo_pt) complexo1, TIPADO_(Complexo_pt) complexo2){
  if(complexo1->real == complexo2->real && complexo1->imag == complexo2->imag){
        return 1;
    }
    return 0;  
}

int TIPADO_(comparaModuloNumeros) (TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2){
    long double modulo1, modulo2;
    modulo1 = TIPADO_(retornaMagnitude)(numComplexo1);
    modulo2 = TIPADO_(retornaMagnitude)(numComplexo2);

    if(fabsl(modulo1-modulo2) > eps){
        if(modulo1 < modulo2)
            return -1;
        if(modulo1 > modulo2)
            return 1;
    }
    else
        return 0;
}

int TIPADO_(comparaAngulosNumeros)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2){
    long double angulo1, angulo2;

    angulo1 = TIPADO_(retornaFase)(numComplexo1);
    angulo2 = TIPADO_(retornaFase)(numComplexo2); 

    if(fabsl(angulo1-angulo2) > eps){
        if(angulo1 < angulo2)
            return -1;
        if(angulo1 > angulo2)
            return 1;
    }
    else
        return 0;
}

void TIPADO_(atribuiNovoValorReal)(TIPADO_(Complexo_pt) numComplexo, TIPO_ novoValor){
    *numComplexo->real = novoValor;
}

void TIPADO_(atribuiNovoValorImaginario)(TIPADO_(Complexo_pt) numComplexo, TIPO_ novoValor){
    *numComplexo->imag = novoValor;
}

void TIPADO_(atribuiNovoValorModulo)(TIPADO_(Complexo_pt) numComplexo, double novoModulo){
    *numComplexo->real = round(novoModulo*cos(TIPADO_(retornaFase)(numComplexo)));
    *numComplexo->imag = round(novoModulo*sin(TIPADO_(retornaFase)(numComplexo)));
}

void TIPADO_(atribuiNovoValorAngulo)(TIPADO_(Complexo_pt) numComplexo, double novoAngulo){
    *numComplexo->real = round(TIPADO_(retornaMagnitude)(numComplexo) * cos(novoAngulo));
    *numComplexo->imag = round(TIPADO_(retornaMagnitude)(numComplexo) * sin(novoAngulo));
}

TIPADO_(Complexo_pt) TIPADO_(retornaConjugado)(TIPADO_(Complexo_pt) numComplexo){
    TIPADO_(Complexo_pt) conjugado = TIPADO_(copiaComplexo)(numComplexo);
    *conjugado->imag *= -1;
    return conjugado;
}

TIPADO_(Complexo_pt) TIPADO_(somaComplexo)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2){
    TIPADO_(Complexo_pt) resultado;
    resultado = TIPADO_(criaComplexo)(0, 0);

    *resultado->real = *numComplexo1->real + *numComplexo2->real;
    *resultado->imag = *numComplexo1->imag + *numComplexo2->imag;;

    return resultado;
}

TIPADO_(Complexo_pt) TIPADO_(subtraiComplexo)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2){
    TIPADO_(Complexo_pt) resultado;
    resultado = TIPADO_(criaComplexo)(0, 0);

    *resultado->real = *numComplexo1->real - *numComplexo2->real;
    *resultado->imag = *numComplexo1->imag - *numComplexo2->imag;;

    return resultado;
}

TIPADO_(Complexo_pt) TIPADO_(divideComplexo)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2){
    TIPADO_(Complexo_pt) resultado;
    resultado = TIPADO_(criaComplexo)(0, 0);
    TIPO_ denominador;

    *resultado->real = (*numComplexo1->real * *numComplexo2->real) + (*numComplexo1->imag * *numComplexo2->imag);
    *resultado->imag = (*numComplexo1->real * *numComplexo2->imag) + (*numComplexo1->imag * *numComplexo2->real);

    denominador = (*numComplexo2->real * *numComplexo2->real) + (*numComplexo2->imag * *numComplexo2->imag);
    if(denominador == 0){
        printf("Nao e possivel realizar a divisao\n");
        exit(1);
    }
    *resultado->real = *resultado->real / denominador;
    *resultado->imag = *resultado->imag / denominador;

    return resultado;
}

TIPADO_(Complexo_pt) TIPADO_(multiplicaComplexo)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2){
    TIPADO_(Complexo_pt) resultado;
    resultado = TIPADO_(criaComplexo)(0, 0);

    *resultado->real = (*numComplexo1->real * *numComplexo2->real) + (*numComplexo1->imag * *numComplexo2->imag * (-1));
    *resultado->imag = (*numComplexo1->real * *numComplexo2->imag) + (*numComplexo1->imag * *numComplexo2->real);

    return resultado;
}

void TIPADO_(acumulaSomando)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2){
    *numComplexo1->real += *numComplexo2->real;
    *numComplexo1->imag += *numComplexo2->imag;
}

void TIPADO_(acumulaMultiplicando)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2){

    TIPO_ copiaReal = *numComplexo1->real;
    TIPO_ copiaImag = *numComplexo1->imag;
    *numComplexo1->real = (*numComplexo1->real * *numComplexo2->real) + (*numComplexo1->imag * *numComplexo2->imag * (-1));
    *numComplexo1->imag = (copiaReal * *numComplexo2->imag) + (copiaImag * *numComplexo2->real);
}

TIPADO_(Complexo_pt) TIPADO_(operacaoComplexo)(TIPADO_(Complexo_pt) numComplexo1, TIPADO_(Complexo_pt) numComplexo2, char *operacao){

    if (strcmp(operacao, "+") == 0){
      return TIPADO_(somaComplexo)(numComplexo1, numComplexo2);
    }
    else if (strcmp(operacao, "-") == 0){
      return TIPADO_(subtraiComplexo)(numComplexo1, numComplexo2);
    }
    else if (strcmp(operacao, "*") == 0){
      return TIPADO_(multiplicaComplexo)(numComplexo1, numComplexo2);
    }
    else if (strcmp(operacao, "/") == 0){
      return TIPADO_(divideComplexo)(numComplexo1, numComplexo2);
    }
    else if (strcmp(operacao, "+=") == 0){
      TIPADO_(acumulaSomando)(numComplexo1, numComplexo2);
      return numComplexo1;
    }
    else if (strcmp(operacao, "*=") == 0){
      TIPADO_(acumulaMultiplicando)(numComplexo1, numComplexo2);
      return numComplexo1;
    }
    else {
      printf ("Simbolo invalido!\n");
    }
}

#endif 
#endif
#endif 
