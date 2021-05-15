#ifdef TIPO_
#ifdef TIPADO_
#ifdef FORMATO_

#define eps 0.00001

struct TIPADO_(Vetor_st){
	  int n; // numero de elementos atual
    int N; // numero máximo de elementos
    int i;
    TIPO_ *elementos;
};

typedef struct TIPADO_(Vetor_st) TIPADO_(Vetor_t);

// O WHILE SERIA AQUI 
void TIPADO_(realocaEspaco)(TIPADO_(Vetor_pt) vetor){ //acho que isso pode ficar dentro da funcao de criar vetor
  if(vetor->n >= vetor->N){
    vetor->elementos = (TIPO_*) realloc(vetor->elementos, 2 * vetor->n * sizeof(TIPO_));
    vetor->N *= 2;
  }
  while(vetor->n <= (vetor->N / 4)){
    vetor->elementos = (TIPO_*) realloc(vetor->elementos, 0.5 * vetor->n * sizeof(TIPO_));
    vetor->N /= 2;
  }
}

TIPADO_(Vetor_pt) TIPADO_(criaVetor)(int n, TIPO_ *elementos){ //Conferir essa parte com a Lara, o tamanho
    TIPADO_(Vetor_pt) vetor = (TIPADO_(Vetor_t*)) malloc(sizeof(TIPADO_(Vetor_t)));
    vetor->elementos = (TIPO_*) malloc(100 * sizeof(TIPO_));
    
    vetor->n = n;
    vetor->N = 100;
    vetor->i = 0;

    TIPADO_(realocaEspaco)(vetor);
    
    for(int c = 0; c < vetor->n; c++){
       *(vetor->elementos+c) = elementos[c];
    }

    return vetor;
}

void TIPADO_(destroiVetor)(TIPADO_(Vetor_pt) vetor){
    free(vetor->elementos);
    vetor->elementos = NULL;
    free(vetor);
    vetor = NULL;
}

TIPO_ TIPADO_(retornaElementos)(TIPADO_(Vetor_pt vetor), int indice){
  return vetor->elementos[indice];
}

void TIPADO_(atribuiVetor)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  vetor1->n = vetor2->n;
  vetor1->N = vetor2->N;
  vetor1->i = vetor2->i;

  for(int c = 0; c < vetor1->n; c++){
    *(vetor1->elementos+c) = *(vetor2->elementos+c);
    }
}

void TIPADO_(imprimeVetor)(TIPADO_(Vetor_pt) vetor){
    printf ("( ");
    for (int i = 0; i < TIPADO_(retornaNumeroAtualElementos)(vetor); i++){
      if (i < TIPADO_(retornaNumeroAtualElementos)(vetor) - 1){
        printf ("%.3"FORMATO_", ", TIPADO_(retornaElementoDePosicaoI)(vetor, i)); 
      }
      else{
        printf ("%.3"FORMATO_" ", TIPADO_(retornaElementoDePosicaoI)(vetor, i));
      }
    }
    printf (")");
}

TIPADO_(Vetor_pt) TIPADO_(criaCopiaVetor)(TIPADO_(Vetor_pt) vetor){
  TIPADO_(Vetor_pt) vetorNovo = TIPADO_(criaVetor)(vetor->n, vetor->elementos);
  return vetorNovo;
}

int TIPADO_(retornaNumeroAtualElementos)(TIPADO_(Vetor_pt) vetor){
    return vetor->n;
}

int TIPADO_(retornaNumeroMaxElementos)(TIPADO_(Vetor_pt) vetor){
  return vetor->N;
}

int TIPADO_(retornaIndice)(TIPADO_(Vetor_pt) vetor){
  return vetor->i;
}

TIPO_ TIPADO_(retornaPrimeiroElemento)(TIPADO_(Vetor_pt) vetor){
  vetor->i = 0;
  return *(vetor->elementos);
}

TIPO_ TIPADO_(retornaProximoElemento)(TIPADO_(Vetor_pt) vetor, int indice){
    if(indice >= vetor->n){
      printf("Nao Existe\n");
      exit(1);
    }
    vetor->i = indice + 1;
    return vetor->elementos[indice+1];
}

TIPO_ TIPADO_(retornaElementoAnterior)(TIPADO_(Vetor_pt) vetor, int indice){
  if(indice == 0){
    printf("Nao Existe\n");
    exit(1);
  }
  vetor->i = indice - 1;
  return vetor->elementos[indice-1];
}

TIPO_ TIPADO_(retornaUltimoElemento)(TIPADO_(Vetor_pt) vetor){
  vetor->i = vetor->n-1;
  return vetor->elementos[vetor->n];
}

TIPO_ TIPADO_(retornaElementoDePosicaoI)(TIPADO_(Vetor_pt) vetor, int indice){
  if(indice >= TIPADO_(retornaNumeroAtualElementos)(vetor) || indice < 0){
    printf("Nao Existe\n");
    exit(1);
  }
  vetor->i = indice;
  return vetor->elementos[indice];
}

void TIPADO_(atribuirValorNaIesimaPosicao)(TIPADO_(Vetor_pt) vetor, int indice, TIPO_ valor){
  if(indice >= TIPADO_(retornaNumeroAtualElementos)(vetor) || indice < 0){
    printf("Nao Existe\n");
    exit(1);
  }
  vetor->elementos[indice] = valor;
  vetor->i = indice;
}

void TIPADO_(adicionaElemento)(TIPADO_(Vetor_pt) vetor, TIPO_ valor){
    vetor->elementos[vetor->n] = valor;
    vetor->n += 1;
    TIPADO_(realocaEspaco)(vetor);
}

void TIPADO_(eliminaElementoDePosicaoI)(TIPADO_(Vetor_pt) vetor, int indice){ //Revisar o significado dessa funcao
    for(int c = indice; c < vetor->n; c++){
        vetor->elementos[c] = vetor->elementos[c+1];
    }
    vetor->n = vetor->n-1;
    TIPADO_(realocaEspaco)(vetor);
}

void TIPADO_(eliminaTodosElementos)(TIPADO_(Vetor_pt) vetor){
    for (int i = 0; i < vetor->n; i++){
      TIPADO_(atribuirValorNaIesimaPosicao)(vetor, i, 0);
    }
} 

TIPO_ TIPADO_(valorDeMaiorModulo)(TIPADO_(Vetor_pt) vetor){
  TIPO_ maior;
  maior = fabsl(vetor->elementos[0]);
  vetor->i = 0;
  for(int c = 0; c < vetor->n; c++){
    if(fabsl(vetor->elementos[c]) > maior){
      maior = vetor->elementos[c];
      vetor->i = c;
    }
  }
  return maior;
}

TIPO_ TIPADO_(valorDeMenorModulo)(TIPADO_(Vetor_pt) vetor){
  TIPO_ menor = fabsl(vetor->elementos[0]);
  for (int i = 0; i < vetor->n; i++){
    if (fabsl(vetor->elementos[i]) < menor){
      menor = vetor->elementos[i];
      vetor->i = i;
    }
  }
  return menor;
}

int TIPADO_(quantElementosDeValorV)(TIPADO_(Vetor_pt) vetor, TIPO_ valor){
    int quant = 0;
    for(int c = 0; c < vetor->n; c++){
        // verificar eps
        if(vetor->elementos[c] == valor || fabsl(vetor->elementos[c]-valor) < eps){
            quant++;
        }
    }
    return quant;
}

//VERIFICAR RETORNO COM A LARA
TIPADO_(Vetor_pt) TIPADO_(retornaVetorComPosicoesQueTemV)(TIPADO_(Vetor_pt) vetor, TIPO_ valor){
    TIPADO_(Vetor_pt) vetorComPosicoes;
    int n = 0;
    for(int i = 0; i < vetor->n; i++){
      if (vetor->elementos[i] == valor){
        n++;
      }
    }
    if(n == 0){
      printf("Nao existe posicoes com esse valor\n");
      exit(1);
    }
    TIPO_ elementos[n];
    n = 0;
    for(int i = 0; i < vetor->n; i++){
      if (vetor->elementos[i] == valor){
        elementos[n] = i;
        n++;
      }
    }
    vetorComPosicoes = TIPADO_(criaVetor)(n, elementos);
    return vetorComPosicoes;
}

int TIPADO_(criterioOrdenacao) (const void * a, const void * b){ // Compara os de conteúdos "a" e "b" e retorna para a função qsort se "a" é maior, menor ou igual que "b"

  if (*(TIPO_*)a == *(TIPO_*)b){
    return 0; // Iguais
  }
  else if (*(TIPO_*)a < *(TIPO_*)b){
    return -1; //  A "a" vem antes da "b"
  }
  else{
    return 1; //  A "a" vem depois da "b"
  }
}

void TIPADO_(ordenarVetor)(TIPADO_(Vetor_pt) vetor){
  qsort(vetor->elementos, vetor->n, sizeof(TIPO_), TIPADO_(criterioOrdenacao));
} 

TIPADO_(Vetor_pt) TIPADO_(intercalaVetor)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  int n = vetor1->n + vetor2->n;
  int iv1 = 0, iv2 =0;
  TIPO_ elementos[n];
  TIPADO_(Vetor_pt) vetorNovo = TIPADO_(criaVetor)(n, elementos);
  TIPADO_(ordenarVetor)(vetor1);
  TIPADO_(ordenarVetor)(vetor2);
  
  for (int i = 0; i < n; i++){
    if(i%2 == 0){
      vetorNovo->elementos[i] = vetor1->elementos[iv1];
      iv1++;
    }
    else{
      vetorNovo->elementos[i] = vetor2->elementos[iv2];
      iv2++;
    }
  }   
  return vetorNovo;
}

TIPADO_(Vetor_pt) TIPADO_(somaVetores)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  TIPADO_(Vetor_pt) vetorNovo = TIPADO_(criaCopiaVetor)(vetor1);

  if(vetor1->n != vetor2->n){
    printf("Nao eh possivel realizar a soma, a quantidade de elementos de cada vetor é diferente\n");
    exit(1);
  }

  for (int i = 0; i < vetorNovo->n; i++){
    vetorNovo->elementos[i] += vetor2->elementos[i];
  }
  return vetorNovo;
} // lara

TIPO_ TIPADO_(produtoInternoVetores) (TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  TIPO_ produtoInterno = 0;

  if(vetor1->n != vetor2->n){
    printf("Nao eh possivel realizar o produto interno, a quantidade de elementos de cada vetor é diferente\n");
    exit(1);
  }

  for (int i = 0; i < vetor1->n; i++){
    produtoInterno += vetor1->elementos[i]*vetor2->elementos[i];
  }
  return produtoInterno;
}

TIPADO_(Vetor_pt) TIPADO_(subtraiVetores)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  TIPADO_(Vetor_pt) vetorNovo = TIPADO_(criaCopiaVetor)(vetor1);

  if(vetor1->n != vetor2->n){
    printf("Nao eh possivel realizar a subtracao, a quantidade de elementos de cada vetor é diferente\n");
    exit(1);
  }

  for (int i = 0; i < vetorNovo->n; i++){
    vetorNovo->elementos[i] -= vetor2->elementos[i];
  }
  return vetorNovo;
} //lara

void TIPADO_(multiplicaVetorPorEscalar)(TIPADO_(Vetor_pt) vetor, double escalar){
  for (int i = 0; i < vetor->n; i++){
    vetor->elementos[i] *= escalar;
  }
}

void TIPADO_(acumulaVetor) (TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){

  if(vetor1->n != vetor2->n){
    printf("Nao eh possivel realizar a soma, a quantidade de elementos de cada vetor é diferente\n");
    exit(1);
  }

  for (int i = 0; i < vetor1->n; i++){
    vetor1->elementos[i] += vetor2->elementos[i];
  }
}

double TIPADO_(mediaArimetica) (TIPADO_(Vetor_pt) vetor){
    double media = 0;
    for (int i = 0; i < vetor->n; i++){
      media += vetor->elementos[i];
    }
    return media/vetor->n;
}

double TIPADO_(varianciaVetor) (TIPADO_(Vetor_pt) vetor){
    double media = TIPADO_(mediaArimetica)(vetor);
    double variancia = 0;
    for (int i = 0; i < TIPADO_(retornaNumeroAtualElementos)(vetor); i++){
      variancia += pow((vetor->elementos[i] - media), 2);
    }
    variancia = variancia/TIPADO_(retornaNumeroAtualElementos)(vetor);
    return variancia;
}

double TIPADO_(desvioPadrao) (TIPADO_(Vetor_pt) vetor){
  double DP;
  DP = sqrt(TIPADO_(varianciaVetor(vetor)));
  
  return DP;
}

//Fiz do jeito "burro" porque nao entendi muito bem o metodo no link que o Saulo colocou no arquivo, depois vou tentar ver melhor
double TIPADO_(medianaVetor) (TIPADO_(Vetor_pt) vetor){
   TIPADO_(ordenarVetor)(vetor);
  double mediana = 0;
  if (vetor->n%2 == 0){
    mediana = (vetor->elementos[(vetor->n/2)-1] + vetor->elementos[vetor->n/2])/2;
  }
  else{
    mediana = vetor->elementos[(vetor->n-1)/2];
  }
  return mediana;
}

#endif
#endif
#endif