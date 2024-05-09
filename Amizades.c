#include "Amizades.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Amizades {
    Usuario *amigo1, *amigo2;
};

Amizades *CriaAmizades(Usuario *usuario1, Usuario *usuario2) {
    if (!usuario1 || !usuario2) return NULL;

    Amizades *amigo = malloc(sizeof(Amizades));
    amigo->amigo1 = usuario1;
    amigo->amigo2 = usuario2;

    return amigo;
}

void LiberaAmizades(Amizades *amizade) {
    if (!amizade) return;
    free(amizade);
}
