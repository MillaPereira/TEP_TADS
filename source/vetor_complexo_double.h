#ifndef VETOR_COMPLEXO_DOUBLE_H
#define VETOR_COMPLEXO_DOUBLE_H

#undef VETOR_H
#undef TIPO_
#undef TIPADO_
#undef TIPO2_
#undef TIPADO2_
#undef FORMATO2_

#include "complexo_double.h"

// Definicao do tipo do vetor
#define TIPO_ D_Complexo_pt
#define TIPADO_(THING) VCD_ ## THING

// Definicao do tipo do complexo
#define TIPO2_ double
#define TIPADO2_(THING) D_ ## THING
#define FORMATO2_ "lf"

#include "vetor_nao_nativo.h"

#endif
