#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Amizade.h"

typedef struct Celula Celula;

struct Celula {
    Usuario *amigo;
    Celula *proximo;
};


struct ListaAmizade {
    Celula *inic, *fim;
};

ListaAmizade *CriaListaAmizade() {
    ListaAmizade *lista = malloc(sizeof(ListaAmizade));
    lista->inic = lista->fim = NULL;
    return lista;
}

void RelacionaAmizade(Usuario *u1, Usuario *u2) {
    if (!u1 || !u2) return;

    InsereAmigoListaAmigo( RetornaListaAmizadeUsuario(u1), u1 );
    InsereAmigoListaAmigo( RetornaListaAmizadeUsuario(u2), u2 );
}

void InsereAmigoListaAmigo(ListaAmizade *lista, Usuario *usuario) {
    if (!lista || !usuario) return;

    Celula *celula = malloc(sizeof(Celula));
    celula->amigo = usuario;
    celula->proximo = NULL;

    if (!lista->inic && !lista->fim) {
        lista->inic = lista->fim = celula;
        return;
    }

    lista->fim->proximo = celula;
    lista->fim = celula;
}

void LiberaListaAmizade(ListaAmizade *lista) {
    if (!lista) return;

    Celula *auxiliar = lista->inic;
    while (auxiliar) {
        auxiliar = lista->inic->proximo;
        free(lista->inic);
        lista->inic = auxiliar;
    }

    free(lista);
}