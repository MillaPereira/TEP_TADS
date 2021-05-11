#ifdef TIPO_ //Complexo_pt
#ifdef TIPADO_ // VCI_() ou VCD_()
#ifdef TIPO2_ // long int ou double
#ifdef TIPADO2_ // I_() ou D_()
#ifdef FORMATO2_ //ld ou lf

struct TIPADO_(Vetor_st){
  int n; // numero de elementos atual
  int N; // numero máximo de elementos
  int i;
  TIPO_ *elementos;
};

typedef struct TIPADO_(Vetor_st) TIPADO_(Vetor_t);

void TIPADO_(realocaEspaco)(TIPADO_(Vetor_pt) vetor){
  if(vetor->n >= vetor->N){
    vetor->elementos = (TIPO_*) realloc(vetor->elementos, 2 * vetor->n * sizeof(TIPO_));
    vetor->N *= 2;
  }
  while(vetor->n <= (vetor->N / 4)){
    vetor->elementos = (TIPO_*) realloc(vetor->elementos, 0.5 * vetor->n * sizeof(TIPO_));
    vetor->N /= 2;
  }
}

void TIPADO_(atribuiElemento)(TIPADO_(Vetor_pt) vetor, int i, TIPO2_ real, TIPO2_ imag){
  *(vetor->elementos+i) = TIPADO2_(criaComplexo)(real, imag);
}

TIPADO2_(Complexo_pt) TIPADO_(retornaComplexo)(TIPADO_(Vetor_pt) vetor, int i){
  return *(vetor->elementos+i);
}

TIPADO_(Vetor_pt) TIPADO_(criaVetor)(int n){
  TIPADO_(Vetor_pt) vetor = (TIPADO_(Vetor_t)*) malloc(sizeof(TIPADO_(Vetor_t)));
  vetor->elementos = (TIPO_*) malloc(100 * sizeof(TIPO_));
  if(vetor->elementos == NULL || vetor == NULL){
    printf("Memória insuficiente!\n");
	  exit(1);
  }
  vetor->n = n;
  vetor->N = 100;
  vetor->i = 0;
  for(int c = 0; c < vetor->N; c++){
    *(vetor->elementos+c) = NULL;
  }

  TIPADO_(realocaEspaco)(vetor);
  
  return vetor;
}

void TIPADO_(destroiVetor)(TIPADO_(Vetor_pt) vetor){
  for(int i = 0; i < vetor->n; i++){
    TIPADO2_(destroiComplexo)(*(vetor->elementos+i));
    vetor->elementos[i] = NULL;
  }
  free(vetor);
  vetor = NULL;
}

TIPO2_ TIPADO_(retornaElementoReal)(TIPADO_(Vetor_pt) vetor, int indice){
  TIPO2_ elemComplexo = TIPADO2_(retornaReal)((TIPADO_(retornaComplexo)(vetor, indice)));
  return elemComplexo;
}

TIPO2_ TIPADO_(retornaElementoImag)(TIPADO_(Vetor_pt) vetor, int indice){
  TIPO2_ elemComplexo = TIPADO2_(retornaImaginario)(TIPADO_(retornaComplexo)(vetor, indice));
  return elemComplexo;
}

void TIPADO_(atribuiVetor)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  vetor1->n = vetor2->n;
  vetor1->N = vetor2->N;
  vetor1->i = vetor2->i;

  for(int c = 0; c < vetor1->n; c++){
    TIPADO2_(atribuiNovoValorReal)(vetor1->elementos[c], TIPADO2_(retornaReal)(vetor2->elementos[c]));
    TIPADO2_(atribuiNovoValorImaginario)(vetor1->elementos[c], TIPADO2_(retornaImaginario)(vetor2->elementos[c]));
  }
}

TIPADO_(Vetor_pt) TIPADO_(criaCopiaVetor)(TIPADO_(Vetor_pt) vetor){
  TIPADO_(Vetor_pt) vetorNovo = TIPADO_(criaVetor)(vetor->n);
  for(int c = 0; c < vetor->n; c++){
    TIPADO_(atribuiElemento)(vetorNovo, c, TIPADO_(retornaElementoReal)(vetor, c), TIPADO_(retornaElementoImag)(vetor, c));
  }
  return vetorNovo;
}

int TIPADO_(retornaNumeroAtualElementos)(TIPADO_(Vetor_pt) vetor){
  return vetor->n;
}

void TIPADO_(imprimeVetor)(TIPADO_(Vetor_pt) vetor){
  printf ("( ");
  for (int i = 0; i < TIPADO_(retornaNumeroAtualElementos)(vetor); i++){
    if (i < TIPADO_(retornaNumeroAtualElementos)(vetor) - 1){
      TIPADO2_(imprimeComplexo)(TIPADO_(retornaComplexo)(vetor, i)); 
      printf(", ");
    }
    else{
      TIPADO2_(imprimeComplexo)(TIPADO_(retornaComplexo)(vetor, i));
    }
  }
  printf (")");
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
  return vetor->elementos[vetor->n-1];
}

TIPO_ TIPADO_(retornaElementoDePosicaoI)(TIPADO_(Vetor_pt) vetor, int indice){
  vetor->i = indice;
  return vetor->elementos[indice];
}

void TIPADO_(atribuirValorNaIesimaPosicao)(TIPADO_(Vetor_pt) vetor, int indice, TIPADO2_(Complexo_pt) valor){  
  TIPADO2_(atribuiComplexo)(TIPADO_(retornaComplexo)(vetor, indice), valor);
}

void TIPADO_(adicionaElemento)(TIPADO_(Vetor_pt) vetor, TIPADO2_(Complexo_pt) novoElemento){
  TIPADO_(atribuirValorNaIesimaPosicao)(vetor, TIPADO_(retornaNumeroAtualElementos)(vetor), novoElemento);
  vetor->n = TIPADO_(retornaNumeroAtualElementos)(vetor) + 1;
}

void TIPADO_(eliminaElementoDePosicaoI)(TIPADO_(Vetor_pt) vetor, int indice){
  for(int c = indice; c < vetor->n; c++){
    vetor->elementos[c] = vetor->elementos[c+1];
  }
  vetor->n = TIPADO_(retornaNumeroAtualElementos)(vetor) - 1;
}

void TIPADO_(eliminaTodosElementos)(TIPADO_(Vetor_pt) vetor){
  TIPADO2_(Complexo_pt) zero = TIPADO2_(criaComplexo)(0, 0);
  for (int i = 0; i < vetor->n; i++){
    TIPADO_(atribuirValorNaIesimaPosicao)(vetor, i, zero);
  }
} 

double TIPADO_(valorDeMaiorModulo)(TIPADO_(Vetor_pt) vetor){
  double maior = TIPADO2_(retornaMagnitude)(TIPADO_(retornaComplexo)(vetor, 0));
  vetor->i = 0;
  for(int c = 0; c < vetor->n; c++){
    if(TIPADO2_(retornaMagnitude)(TIPADO_(retornaComplexo)(vetor, c)) > maior){
      maior = TIPADO2_(retornaMagnitude)(TIPADO_(retornaComplexo)(vetor, c));
      vetor->i = c;
    }
  }
  return maior;
}

double TIPADO_(valorDeMenorModulo)(TIPADO_(Vetor_pt) vetor){
  double menor = TIPADO2_(retornaMagnitude)(TIPADO_(retornaComplexo)(vetor, 0));
  vetor->i = 0;
  for (int c = 0; c < vetor->n; c++){
    if (TIPADO2_(retornaMagnitude)(TIPADO_(retornaComplexo)(vetor, c)) < menor){
      menor = TIPADO2_(retornaMagnitude)(TIPADO_(retornaComplexo)(vetor, c));
      vetor->i = c;
    }
  }
  return menor;
}

int TIPADO_(quantElementosDeValorV)(TIPADO_(Vetor_pt) vetor, TIPADO2_(Complexo_pt) valor){
  int quant = 0;
  for(int c = 0; c < vetor->n; c++){
    if(TIPADO2_(comparaModuloNumeros)(TIPADO_(retornaComplexo)(vetor, c), valor) == 0){
      quant++;
    }
  }
  return quant;
}

int *TIPADO_(retornaVetorComPosicoesQueTemV)(TIPADO_(Vetor_pt) vetor, TIPADO2_(Complexo_pt) valor){
  int n = 0;
  int *elementos;
  for(int i = 0; i < TIPADO_(retornaNumeroAtualElementos)(vetor); i++){
    if (TIPADO2_(comparaComplexos)(TIPADO_(retornaElementoDePosicaoI)(vetor, i), valor) == 1){
      elementos[n] = i;
      printf ("n -> %d\n", elementos[n]);
      n++;
    }
  }
  return elementos;
}

int TIPADO_(criterioOrdenacao) (const void * a, const void * b){
  if (TIPADO2_(retornaMagnitude)(*(TIPO_*)a) == TIPADO2_(retornaMagnitude)(*(TIPO_*)b)){
    return 0; // Iguais
  }
  else if (TIPADO2_(retornaMagnitude)(*(TIPO_*)a) < TIPADO2_(retornaMagnitude)(*(TIPO_*)b)){
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
  int n = TIPADO_(retornaNumeroAtualElementos)(vetor1) + TIPADO_(retornaNumeroAtualElementos)(vetor2);
  int iv1 = 0, iv2 = 0;
  TIPADO_(Vetor_pt) vetorNovo = TIPADO_(criaVetor)(n);
  TIPADO_(ordenarVetor)(vetor1);
  TIPADO_(ordenarVetor)(vetor2);
  
  for (int i = 0; i < n; i++){
    TIPADO_(atribuiElemento)(vetorNovo, i, 0, 0);
    if(i%2 == 0){
      TIPADO_(atribuirValorNaIesimaPosicao)(vetorNovo, i, TIPADO_(retornaElementoDePosicaoI)(vetor1, iv1));
      iv1++;
    }
    else{
      TIPADO_(atribuirValorNaIesimaPosicao)(vetorNovo, i, TIPADO_(retornaElementoDePosicaoI)(vetor2, iv2));
      iv2++;
    }
  }   
  return vetorNovo;
}

TIPADO_(Vetor_pt) TIPADO_(somaVetores)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  TIPADO_(Vetor_pt) vetor = TIPADO_(criaCopiaVetor)(vetor1);
  TIPADO2_(Complexo_pt) soma;
  for(int c = 0; c < vetor1->n; c++){
    soma = TIPADO2_(somaComplexo)(TIPADO_(retornaComplexo)(vetor1, c), TIPADO_(retornaComplexo)(vetor2, c));
    TIPADO2_(atribuiComplexo)(TIPADO_(retornaComplexo)(vetor, c), soma);
  }
  return vetor;
}

TIPO_ TIPADO_(produtoInternoVetores) (TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  TIPO_ produtoInterno = TIPADO2_(criaComplexo)(0,0);
  if(vetor1->n != vetor2->n){
    printf("Nao eh possivel realizar o produto interno, a quantidade de elementos de cada vetor é diferente\n");
    exit(1);
  }
  for (int i = 0; i < vetor1->n; i++){
    TIPADO2_(acumulaSomando)(produtoInterno, TIPADO2_(multiplicaComplexo)(TIPADO_(retornaComplexo)(vetor1, i), TIPADO_(retornaComplexo)(vetor2, i)));
  }
  return produtoInterno;
}

TIPADO_(Vetor_pt) TIPADO_(subtraiVetores)(TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  TIPADO_(Vetor_pt) vetor = TIPADO_(criaCopiaVetor)(vetor1);
  TIPADO2_(Complexo_pt) subtracao;
  for(int c = 0; c < vetor1->n; c++){
    subtracao = TIPADO2_(subtraiComplexo)(TIPADO_(retornaComplexo)(vetor1, c), TIPADO_(retornaComplexo)(vetor2, c));
    TIPADO2_(atribuiComplexo)(TIPADO_(retornaComplexo)(vetor, c), subtracao);
  }
  return vetor;
}

void TIPADO_(multiplicaVetorPorEscalar)(TIPADO_(Vetor_pt) vetor, double escalar){
  for(int c = 0; c < vetor->n; c++){
    TIPADO2_(atribuiNovoValorReal)(TIPADO_(retornaComplexo)(vetor, c), TIPADO2_(retornaReal)(TIPADO_(retornaComplexo)(vetor, c))*escalar);
    TIPADO2_(atribuiNovoValorImaginario)(TIPADO_(retornaComplexo)(vetor, c), TIPADO2_(retornaImaginario)(TIPADO_(retornaComplexo)(vetor, c))*escalar);
  }
} 

void TIPADO_(acumulaVetor) (TIPADO_(Vetor_pt) vetor1, TIPADO_(Vetor_pt) vetor2){
  TIPO2_ real, imaginario;

  for(int c = 0; c < vetor1->n; c++){
    real = TIPADO2_(retornaReal)(TIPADO_(retornaComplexo)(vetor1, c)) + TIPADO2_(retornaReal)(TIPADO_(retornaComplexo)(vetor2, c));
    imaginario = TIPADO2_(retornaImaginario)(TIPADO_(retornaComplexo)(vetor1, c)) + TIPADO2_(retornaImaginario)(TIPADO_(retornaComplexo)(vetor2, c));

    TIPADO2_(atribuiNovoValorReal)(TIPADO_(retornaComplexo)(vetor1, c), real);
    TIPADO2_(atribuiNovoValorImaginario)(TIPADO_(retornaComplexo)(vetor1, c), imaginario);
  }
}

double TIPADO_(mediaAritimetica) (TIPADO_(Vetor_pt) vetor){
  double media = 0;
  for (int i = 0; i < TIPADO_(retornaNumeroAtualElementos)(vetor); i++){
    media += TIPADO2_(retornaMagnitude)(TIPADO_(retornaComplexo)(vetor, i));
  }
  return media/TIPADO_(retornaNumeroAtualElementos)(vetor);
}

double TIPADO_(varianciaVetor) (TIPADO_(Vetor_pt) vetor){
  double media = TIPADO_(mediaAritimetica)(vetor);
  double variancia = 0;
  
  for (int i = 0; i < vetor->n; i++){
    variancia += pow((TIPADO2_(retornaMagnitude)(TIPADO_(retornaComplexo)(vetor, i)) - media), 2);
  }
  variancia = variancia/TIPADO_(retornaNumeroAtualElementos)(vetor);
  return variancia;
}

double TIPADO_(desvioPadrao) (TIPADO_(Vetor_pt) vetor){
  double DP;
  DP = sqrt(TIPADO_(varianciaVetor(vetor)));
  return DP;
}

double TIPADO_(medianaVetor) (TIPADO_(Vetor_pt) vetor){
  TIPADO_(ordenarVetor)(vetor);
  int n = TIPADO_(retornaNumeroAtualElementos)(vetor);
  int meio = n/2;
  double mediana = 0;
  if (n%2 == 0){
    mediana = ((TIPADO2_(retornaMagnitude)(TIPADO_(retornaElementoDePosicaoI)(vetor, meio))) + (TIPADO2_(retornaMagnitude)(TIPADO_(retornaElementoDePosicaoI)(vetor, meio-1))))/2;
  }
  else{
    
    mediana = TIPADO2_(retornaMagnitude)(TIPADO_(retornaElementoDePosicaoI)(vetor, meio));
  }
  return mediana;
}

#endif 
#endif
#endif
#endif
#endif
