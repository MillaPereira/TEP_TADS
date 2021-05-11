#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "racionais.h"

#include "complexoLongInt.h"
#include "complexo-double.h"
#include "converteComplexo.h"

#include "vetorLongInt.h"
#include "vetorDouble.h"
#include "vetor_complexo_double.h"
#include "vetor_complexo_int.h"

#include "complexo_nao_nativo.h"

int main(void) { 
  printf ("\n===== TESTE COM RACIONAIS =====\n\n");

  printf ("Criando racionais...\n\n");
  Racional_pt numRacional1 = criaNumRacional(1, 2);
  Racional_pt numRacional2 = criaNumRacional(4, 3);

  printf ("Racionais criados: \n");
  printf("Racional 1: ");
  imprimeRacional(numRacional1);
  printf("Racional 2: ");
  imprimeRacional(numRacional2);

  printf ("\n");

  printf ("Soma dos racionais 1 e 2: ");
  Racional_pt resultRacional = somaRacionais(numRacional1, numRacional2);
  imprimeRacional(resultRacional);

  printf ("Subtracao dos racionais 1 e 2: ");
  resultRacional = subtraiRacionais(numRacional1, numRacional2);
  imprimeRacional(resultRacional);

  printf ("Multiplicacao dos racionais 1 e 2: ");
  resultRacional = multiplicaRacionais(numRacional1, numRacional2);
  imprimeRacional(resultRacional);

  printf ("Divisao dos racionais 1 e 2: ");
  resultRacional = divideRacionais(numRacional1, numRacional2);
  imprimeRacional(resultRacional);

  printf ("Quadrado do racional 1: ");
  resultRacional = elevaAoQuadrado(numRacional1);
  imprimeRacional(resultRacional);

  printf ("Raiz do racional 1: ");
  double raiz = raizQuadrada(numRacional1);
  printf ("%f\n", raiz);
  printf ("\n");

  printf ("O numero 0.31415 convertido em racional: ");
  resultRacional = converteRealEmRacional(0.31415);
  imprimeRacional(resultRacional);

  printf ("O numero 5/6 convertido em real: ");
  Racional_pt numRacional3 = criaNumRacional(5, 6);
  double real = converteRacionalEmReal(numRacional3);
  printf ("%f\n", real);

  printf ("\nDestruindo racionais...\n");
  destroiRacional(numRacional1);
  destroiRacional(numRacional2);
  destroiRacional(resultRacional);

  printf ("\n\n===== TESTE COM COMPLEXOS NATIVOS =====\n\n");

  printf ("Criando complexos...\n\n");
  D_Complexo_pt numComplexo1 = D_criaComplexo(1, 2);
  D_Complexo_pt numComplexo2 = D_criaComplexo(4, 3);

  printf ("Complexos criados: \n");
  printf("Complexo 1: ");
  D_imprimeComplexo(numComplexo1);
  printf("\nComplexo 2: ");
  D_imprimeComplexo(numComplexo2);

  printf ("\n\nSoma dos complexos 1 e 2: ");
  D_Complexo_pt resultComplexo = D_operacaoComplexo(numComplexo1, numComplexo2, "+");
  D_imprimeComplexo(resultComplexo);

  printf ("\nSubtracao dos complexos 1 e 2: ");
  resultComplexo = D_operacaoComplexo(numComplexo1, numComplexo2, "-");
  D_imprimeComplexo(resultComplexo);

  printf ("\nMultiplicação dos complexos 1 e 2: ");
  resultComplexo = D_operacaoComplexo(numComplexo1, numComplexo2, "*");
  D_imprimeComplexo(resultComplexo);

  printf ("\nDivisão dos complexos 1 e 2: ");
  resultComplexo = D_operacaoComplexo(numComplexo1, numComplexo2, "/");
  D_imprimeComplexo(resultComplexo);
  
  printf ("\nMagnitude do complexo 1: ");
  double modulo1 = D_retornaMagnitude(numComplexo1);
  printf ("%lf", modulo1);

  printf ("\nAngulo em radianos do complexo 1: ");
  double angulo1 = D_retornaFase(numComplexo1);
  printf ("%lf", angulo1);

  printf ("\n\nDestruindo Complexos...");
  D_destroiComplexo(numComplexo1);
  D_destroiComplexo(numComplexo2);
  D_destroiComplexo(resultComplexo);
 
  printf ("\n\n===== TESTE COM COMPLEXOS DO TIPO RACIONAL =====\n\n");

  printf ("Criando complexos do tipo racional...\n\n");
  R_Complexo_pt complexoRacional1 = R_criaComplexo(3, 1, 4, 1);
  R_Complexo_pt complexoRacional2 = R_criaComplexo(4, 1, 4, 1);

  printf ("Complexos racionais criados: \n");
  R_imprimeComplexo(complexoRacional1);
  R_imprimeComplexo(complexoRacional2);

  printf ("\n");

  printf ("Soma dos complexos racionais 1 e 2: ");
  R_Complexo_pt resultComplexRacional = R_operacaoComplexo(complexoRacional1, complexoRacional2, "+");
  R_imprimeComplexo(resultComplexRacional);

  printf ("Subtracao dos complexos racionais 1 e 2: ");
  resultComplexRacional = R_operacaoComplexo(complexoRacional1, complexoRacional2, "-");
  R_imprimeComplexo(resultComplexRacional);

  printf ("Multiplicacao dos complexos racionais 1 e 2: ");
  resultComplexRacional = R_operacaoComplexo(complexoRacional1, complexoRacional2, "*");
  R_imprimeComplexo(resultComplexRacional);

  printf ("Divisao dos complexos racionais 1 e 2: ");
  resultComplexRacional = R_operacaoComplexo(complexoRacional1, complexoRacional2, "/");
  R_imprimeComplexo(resultComplexRacional);

  printf ("Magnitude do complexo racional 2: ");
  double modulo2 = R_retornaMagnitude(complexoRacional2);
  printf ("%lf\n", modulo2);

  printf ("Angulo em radianos do complexo 2: ");
  double angulo2 = R_retornaFase(complexoRacional2);
  printf ("%lf\n", angulo2);

  printf ("\nDestruindo Complexos Racionais...");
  R_destroiComplexo(complexoRacional1);
  R_destroiComplexo(complexoRacional2);
  R_destroiComplexo(resultComplexRacional);

  printf ("\n\n===== TESTE COM FUNÇÕES DE CONVERSÃO DE COMPLEXOS =====\n\n");

  printf ("Criando complexos do tipo long int...\n");
  I_Complexo_pt complexoLI1 = I_criaComplexo(1, 2);
  I_Complexo_pt complexoLI2 = I_criaComplexo(2, 3);

  printf ("Criando complexos do tipo double...\n");
  D_Complexo_pt complexoD1 = D_criaComplexo(4.0, 5.0);
  D_Complexo_pt complexoD2 = D_criaComplexo(6.0, 7.0);

  printf ("Criando complexos do tipo racional...\n");
  R_Complexo_pt complexoR1 = R_criaComplexo(1, 2, 3, 4);
  R_Complexo_pt complexoR2 = R_criaComplexo(2, 3, 4, 5);

  printf ("\nComplexos inteiros criados: \n");
  printf ("Complexo inteiro 1: ");
  I_imprimeComplexo(complexoLI1);
  printf("\n");
  printf ("Complexo inteiro 2: ");
  I_imprimeComplexo(complexoLI2);

  printf ("\n\nComplexos reais criados: \n");
  printf ("Complexo real 1: ");
  D_imprimeComplexo(complexoD1);
  printf("\n");
  printf ("Complexo real 2: ");
  D_imprimeComplexo(complexoD2);

  printf ("\n\nComplexos racionais criados: \n");
  printf ("Complexo racional 1: ");
  R_imprimeComplexo(complexoR1);
  printf ("Complexo racional 2: ");
  R_imprimeComplexo(complexoR2);
  printf ("\n");

  printf("\nComplexo inteiro 1 convertido para real: ");
  D_Complexo_pt dComplexo = converteLongIntParaDouble(complexoLI1);
  D_imprimeComplexo(dComplexo);

  printf("\nComplexo inteiro 2 convertido para racional: ");
  rComplexo = converteLongIntParaRacional(complexoLI2);
  R_imprimeComplexo(rComplexo);

  printf("Complexo real 1 convertido para inteiro: ");
  I_Complexo_pt iComplexo = converteDoubleParaLongInt(complexoD1);
  I_imprimeComplexo(iComplexo);

  printf("\nComplexo real 2 convertido para racional: ");
  R_Complexo_pt rComplexo = converteDoubleParaRacional(complexoD2);
  R_imprimeComplexo(rComplexo);

  printf("\nComplexo racional 1 convertido para real: ");
  dComplexo = converteRacionalParaDouble(complexoR1);
  D_imprimeComplexo(dComplexo);

  printf("\nComplexo racional 2 convertido para inteiro: ");
  iComplexo = converteRacionalParaLongInt(complexoR2);
  I_imprimeComplexo(iComplexo);

  printf("\nDestruindo complexos... \n");
  I_destroiComplexo(complexoLI1);
  I_destroiComplexo(complexoLI2);
  //I_destroiComplexo(iComplexo);
  D_destroiComplexo(complexoD1);
  D_destroiComplexo(complexoD2);
  //D_destroiComplexo(dComplexo);
  R_destroiComplexo(complexoR1);
  R_destroiComplexo(complexoR2);
  //R_destroiComplexo(rComplexo);

  printf ("\n\n===== TESTE COM VETORES NATIVOS =====\n\n");

  printf ("Criando vetores...\n\n");
  double elementos1[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  double elementos2[] = {6.0, 7.0, 8.0, 9.0, 10.0};
  D_Vetor_pt vetor1 = D_criaVetor(5, elementos1);
  D_Vetor_pt vetor2 = D_criaVetor(5, elementos2);

  printf ("Vetores criados: \n");
  printf("Vetor 1: ");
  D_imprimeVetor(vetor1);
  printf("\nVetor 2: ");
  D_imprimeVetor(vetor2);

  printf ("\n\nSoma dos vetores 1 e 2: ");
  D_Vetor_pt resultVetor = D_somaVetores(vetor1, vetor2);
  D_imprimeVetor(resultVetor);

  printf ("\nSubtracao dos vetores 1 e 2: ");
  resultVetor = D_subtraiVetores(vetor1, vetor2);
  D_imprimeVetor(resultVetor);

  printf ("\nMultiplicacao do vetore 1 por um escalar 5: ");
  D_multiplicaVetorPorEscalar(vetor1, 5);
  D_imprimeVetor(vetor1);

  printf ("\nProduto interno dos vetores 1 e 2: ");
  double produto = D_produtoInternoVetores(vetor1, vetor2);
  printf ("%.3lf", produto);

  printf ("\n\nIntercala vetor 1 com vetor 2: ");
  resultVetor = D_intercalaVetor(vetor1, vetor2);
  D_imprimeVetor(resultVetor);

  printf ("\nValor de menor modulo do vetor 1: ");
  double valor = D_valorDeMenorModulo(vetor1);
  printf ("%.3lf", valor);

  printf ("\nValor de maior modulo do vetor 1: ");
  valor = D_valorDeMaiorModulo(vetor1);
  printf ("%.3lf", valor);

  printf ("\nMedia aritimetica do vetor 1: ");
  valor = D_mediaArimetica(vetor1);
  printf ("%.3lf", valor);

  printf ("\nVariancia de vetor 1: ");
  valor = D_varianciaVetor(vetor1);
  printf ("%.3lf", valor);
  
  printf ("\nDesvio padrao do vetor 1: ");
  valor = D_desvioPadrao(vetor1);
  printf ("%.3lf", valor);

  printf ("\nMediana do vetor 1: ");
  valor = D_medianaVetor(vetor1);
  printf ("%.3lf", valor);

  printf ("\n\nAtribui valor 67.3 na posicao 3 do vetor 1: ");
  D_atribuirValorNaIesimaPosicao(vetor1, 2, 67.3);
  D_imprimeVetor(vetor1);

  printf ("\nAdiciona elemento de valor 45.6 no vetor 2: ");
  D_adicionaElemento(vetor2, 45.6);
  D_imprimeVetor(vetor2);

  printf ("\nElimina elemento da posicao 2 do vetor 1: ");
  D_eliminaElementoDePosicaoI(vetor1, 1);
  D_imprimeVetor(vetor1);

  printf("\n\nDestruindo vetores... \n");
  D_destroiVetor(vetor1);
  D_destroiVetor(vetor2);
  D_destroiVetor(resultVetor);

  printf ("\n\n===== TESTE COM VETORES DO TIPO COMPLEXO =====\n\n");

  printf ("Criando vetores...\n\n");
  VCD_Vetor_pt vetorCompl1 = VCD_criaVetor(5);
  VCD_Vetor_pt vetorCompl2 = VCD_criaVetor(5);

  VCD_atribuiElemento(vetorCompl1, 0, 1.0, 1.0);
  VCD_atribuiElemento(vetorCompl1, 1, 1.0, 2.0);
  VCD_atribuiElemento(vetorCompl1, 2, 1.0, 3.0);
  VCD_atribuiElemento(vetorCompl1, 3, 1.0, 4.0);
  VCD_atribuiElemento(vetorCompl1, 4, 1.0, 5.0);

  VCD_atribuiElemento(vetorCompl2, 0, 2.0, 6.0);
  VCD_atribuiElemento(vetorCompl2, 1, 2.0, 7.0);
  VCD_atribuiElemento(vetorCompl2, 2, 2.0, 8.0);
  VCD_atribuiElemento(vetorCompl2, 3, 2.0, 9.0);
  VCD_atribuiElemento(vetorCompl2, 4, 2.0, 10.0);
  
  printf ("Vetores criados: \n");
  printf("Vetor complexo 1: ");
  VCD_imprimeVetor(vetorCompl1);
  printf("\nVetor complexo 2: ");
  VCD_imprimeVetor(vetorCompl2);

  printf ("\n\nSoma dos vetores do tipo complexo 1 e 2: \n");
  VCD_Vetor_pt resultVetorCompl = VCD_somaVetores(vetorCompl1, vetorCompl2);
  VCD_imprimeVetor(resultVetorCompl);

  printf ("\nSubtracao dos vetores do tipo complexo 1 e 2: \n");
  resultVetorCompl = VCD_subtraiVetores(vetorCompl1, vetorCompl2);
  VCD_imprimeVetor(resultVetorCompl);

  printf ("\nMultiplicacao do vetor 1 por um escalar 5: \n");
  VCD_multiplicaVetorPorEscalar(vetorCompl1, 5);
  VCD_imprimeVetor(vetorCompl1);

  printf ("\nProduto interno dos vetores 1 e 2: ");
  D_Complexo_pt produto2 = VCD_produtoInternoVetores(vetorCompl1, vetorCompl2);
  D_imprimeComplexo(produto2);

  printf ("\n\nIntercala vetor 1 com vetor 2: \n");
  resultVetorCompl = VCD_intercalaVetor(vetorCompl1, vetorCompl2);
  VCD_imprimeVetor(resultVetorCompl);

  printf ("\nValor de menor modulo do vetor 1: ");
  double valorCompl = VCD_valorDeMenorModulo(vetorCompl1);
  printf ("%.3lf", valorCompl);

  printf ("\nValor de maior modulo do vetor 1: ");
  valorCompl = VCD_valorDeMaiorModulo(vetorCompl1);
  printf ("%.3lf", valorCompl);

  printf ("\nMedia aritimetica do vetor 1: ");
  valorCompl = VCD_mediaAritimetica(vetorCompl1);
  printf ("%.3lf", valorCompl);

  printf ("\nVariancia de vetor 1: ");
  valorCompl = VCD_varianciaVetor(vetorCompl1);
  printf ("%.3lf", valorCompl);
  
  printf ("\nDesvio padrao do vetor 1: ");
  valorCompl = VCD_desvioPadrao(vetorCompl1);
  printf ("%.3lf", valorCompl);

  printf ("\nMediana do vetor 1: ");
  valorCompl = VCD_medianaVetor(vetorCompl1);
  printf ("%.3lf", valorCompl);

  printf ("\n\nAtribui valor 67.3 + 45.8i na posicao 3 do vetor 1: \n");
  D_Complexo_pt num = D_criaComplexo(67.3, 45.8);
  VCD_atribuirValorNaIesimaPosicao(vetorCompl1, 2, num);
  VCD_imprimeVetor(vetorCompl1);

  printf ("\nAdiciona elemento de valor 67.3 + 45.8i no vetor 2: \n");
  VCD_adicionaElemento(vetorCompl2, num);
  VCD_imprimeVetor(vetorCompl2);

  printf ("\nElimina elemento da posicao 2 do vetor 1: \n");
  VCD_eliminaElementoDePosicaoI(vetorCompl1, 1);
  VCD_imprimeVetor(vetorCompl1);

  printf("\n\n");
  printf("===== FIM! =====\n");

  return 0;
}
