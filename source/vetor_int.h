#ifndef VETOR_INT_H
#define VETOR_INT_H

#undef VETOR_H
#undef TIPO_
#undef TIPADO_ 
#undef FORMATO_

/* Definicao do tipo de vetor nativo da linguagem*/ 
#define TIPO_ long int
#define TIPADO_(THING) I_ ## THING
#define FORMATO_ "ld"

#include "vetor.h"

#endif