#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 

#include "complexo_double.h"
#include "complexo_long_int.h"
#include "complexo_nao_nativo.h"
#include "complexo.h"
#include "racionais.h"
#include "conversao.h"
 
I_Complexo_pt converteDoubleParaLongInt(D_Complexo_pt dComplexo){
    long int real = D_retornaReal(dComplexo);
    long int imag = D_retornaImaginario(dComplexo);
    I_Complexo_pt iComplexo = I_criaComplexo(real, imag);
    return iComplexo;
}

D_Complexo_pt converteLongIntParaDouble(I_Complexo_pt iComplexo){
    double real = I_retornaReal(iComplexo);
    double imag = I_retornaImaginario(iComplexo);
    D_Complexo_pt dComplexo = D_criaComplexo(real, imag);
    return dComplexo;
}

R_Complexo_pt converteDoubleParaRacional(D_Complexo_pt dComplexo){
    Racional_pt real = converteRealEmRacional(D_retornaReal(dComplexo));
    Racional_pt imag = converteRealEmRacional(D_retornaImaginario(dComplexo));
    R_Complexo_pt rComplexo = R_criaComplexo(retornaNum(real), retornaDen(real), retornaNum(imag), retornaDen(imag));
    return rComplexo;
}

D_Complexo_pt converteRacionalParaDouble(R_Complexo_pt rComplexo){
    double real = converteRacionalEmReal(R_retornaReal(rComplexo));
    double imag = converteRacionalEmReal(R_retornaImaginario(rComplexo));
    D_Complexo_pt dComplexo = D_criaComplexo(real, imag);
    return dComplexo;
}

I_Complexo_pt converteRacionalParaLongInt(R_Complexo_pt rComplexo){
    long int real = converteRacionalEmReal(R_retornaReal(rComplexo));
    long int imag = converteRacionalEmReal(R_retornaImaginario(rComplexo));
    I_Complexo_pt iComplexo = I_criaComplexo(real, imag);
    return iComplexo;
}

R_Complexo_pt converteLongIntParaRacional(I_Complexo_pt iComplexo){
    double r = I_retornaReal(iComplexo);
    double i = I_retornaImaginario(iComplexo);
    Racional_pt real = converteRealEmRacional(r);
    Racional_pt imag = converteRealEmRacional(i);
    R_Complexo_pt rComplexo = R_criaComplexo(retornaNum(real), retornaDen(real), retornaNum(imag), retornaDen(imag));
    return rComplexo;
}
