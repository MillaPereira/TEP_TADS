#ifndef VETOR_DOUBLE_H
#define VETOR_DOUBLE_H

#undef VETOR_H
#undef TIPO_
#undef TIPADO_ 
#undef FORMATO_

// Definicao do tipo do vetor nativo da linguagem 
#define TIPO_ double
#define TIPADO_(THING) D_ ## THING
#define FORMATO_ "lf"

#include "vetor.h"

#endif