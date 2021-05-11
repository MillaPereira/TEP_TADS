#ifndef VETOR_COMPLEXO_INT_H
#define VETOR_COMPLEXO_INT_H

#undef VETOR_H
#undef TIPO_
#undef TIPO2_
#undef TIPADO_
#undef TIPADO2_
#undef FORMATO2_


#include "complexo_long_int.h"

// Definicao do tipo do vetor
#define TIPO_ I_Complexo_pt
#define TIPADO_(THING) VCI_ ## THING

// Definicao do tipo do complexo
#define TIPO2_ long int
#define TIPADO2_(THING) I_ ## THING
#define FORMATO2_ "ld"

#include "vetor_nao_nativo.h"

#endif