#ifndef AMIZADES_H_
#define AMIZADES_H_

#include "Usuario.h"

typedef struct Amizades Amizades;

Amizades *CriaAmizades(Usuario *usuario1, Usuario *usuario2);

void LiberaAmizades(Amizades *amizade);

#endif // !AMIZADES_H_

