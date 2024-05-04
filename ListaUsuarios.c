#include "ListaUsuarios.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Celula Celula;

struct Celula {
    Usuario *user;
    Celula *ant, *prox;
};

struct ListaUsuarios {
    Celula *first, *last;
};

ListaUsuarios *IniciaListaUsuarios() {
    ListaUsuarios *l = malloc(sizeof(LiberaUsuario));
    l->first = l->last = NULL;
    return l;
}

void InsereListaUsuario(ListaUsuarios *userList, Usuario *user) {
    if (!userList || !user) return;

    Celula *c = malloc(sizeof(Celula));
    c->user = user;
    c->ant = NULL;
    c->prox = NULL;

    if (EhListaUsuarioVazia(userList)) {
        userList->first = userList->last = c;
        return;
    }

    c->ant = userList->last;
    userList->last->prox = c;
    userList->last = c;
}

void RetiraListaUsuario(ListaUsuarios *userList, Usuario *user) {
    if (!userList || !user) return;

    Celula *aux;

    // se for o ultimo da lista
    if (userList->last->user== user) {
       aux = userList->last;  free(aux);
       userList->last = userList->last->ant;
       return;
    }

    for (aux = userList->first; aux; aux = aux->prox) {
        if (aux->user == user) {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            free(aux);
            return;
        }
    }

}

void ImprimeListaUsuario(ListaUsuarios *userList) {
    if (!userList) return;
    Celula *aux;
    for (aux = userList->first; aux; aux = aux->prox) {
        ImprimeUsuario(aux->user);
    }
}

void LiberaListaUsuario(ListaUsuarios *userList) {
    if (!userList) return;

    Celula *aux;
    for (aux = userList->first; aux; aux = aux->prox) {
        userList->first = aux;
        free(userList->first);
    }
}

int EhListaUsuarioVazia(ListaUsuarios *userList) {
    if (!userList) return 0;
    if (userList->first) return 0;
    return 1;
}