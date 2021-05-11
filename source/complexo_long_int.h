#ifndef COMPLEXO_LONG_INT_H
#define COMPLEXO_LONG_INT_H

#undef COMPLEXO_H
#undef TIPO_
#undef TIPADO_
#undef FORMATO_

// Definicao do tipo long int
#define TIPO_ long int
#define TIPADO_(THING) I_ ## THING
#define FORMATO_ "ld"

#include "complexo.h"
#endif