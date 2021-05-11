#ifndef CONVERTE_COMPLEXO_H
#define CONVERTE_COMPLEXO_H

#include "racionais.h"
#include "complexo_long_int.h"
#include "complexo_double.h"
#include "complexo_nao_nativo.h"

I_Complexo_pt converteDoubleParaLongInt(D_Complexo_pt dComplexo);

D_Complexo_pt converteLongIntParaDouble(I_Complexo_pt iComplexo);

R_Complexo_pt converteDoubleParaRacional(D_Complexo_pt dComplexo);

D_Complexo_pt converteRacionalParaDouble(R_Complexo_pt rComplexo);

I_Complexo_pt converteRacionalParaLongInt(R_Complexo_pt rComplexo);

R_Complexo_pt converteLongIntParaRacional(I_Complexo_pt iComplexo);

#endif
