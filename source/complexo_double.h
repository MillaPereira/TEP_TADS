#ifndef COMPLEXO_DOUBLE_H
#define COMPLEXO_DOUBLE_H

#undef COMPLEXO_H
#undef TIPO_
#undef TIPADO_
#undef FORMATO_

// Definicao do tipo double 
#define TIPO_ double
#define TIPADO_(THING) D_ ## THING
#define FORMATO_ "lf"

#include "complexo.h"
#endif