#ifndef AMIZADE_H_
#define AMIZADE_H_

typedef struct Usuario Usuario;
#include "Usuario.h"

typedef struct ListaAmizade ListaAmizade;

ListaAmizade *CriaListaAmizade();

void RelacionaAmizade(Usuario *u1, Usuario *u2);

void InsereAmigoListaAmigo(ListaAmizade *lista, Usuario *usuario);

void LiberaListaAmizade(ListaAmizade *lista);


#endif // !_LISTAAMIZADE_H_
