#ifndef AMIZADE_H_
#define AMIZADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Usuario Usuario;
#include "Usuario.h"
typedef struct ListaUsuario ListaUsuario;
#include "ListaUsuario.h"

typedef struct ListaAmizade ListaAmizade;
typedef struct Amizade Amizade;

ListaAmizade *CriaListaAmizade();

void LeArquivoAmizade(FILE *fAmizades, ListaAmizade *amizades, ListaUsuario *lista);

Amizade *CriaAmizade(Usuario *usuario1, Usuario *usuario2);

void InsereAmizadeLista(ListaAmizade *lista, Amizade *amgs);

void LiberaListaAmizade(ListaAmizade *lista);

void Similaridades(ListaAmizade *lista);

void ImprimeSimiladiridade(Amizade *relacao, FILE *file);


#endif // !_LISTAAMIZADE_H_
