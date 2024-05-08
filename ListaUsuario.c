#include "ListaUsuario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula Celula;

struct Celula {
    Usuario *usuario;
    Celula *proximo;
};
struct ListaUsuario {
    Celula *prim, *ult;
};

ListaUsuario *IniciaListaUsuario() {
    ListaUsuario *l = malloc(sizeof(ListaUsuario));
    if (!l) {
        printf("Erro ao alocar memoria para a lista de usuario!\n");
        return NULL;
    }

    l->prim = l->ult = NULL;
    return l;
}

void LeUsuariosDoArquivo(ListaUsuario *lista) {
    if (!lista) return;
    
    FILE *fAmizades = NULL;
    fAmizades = fopen("Entradas/amizade.txt", "r");
    if (!fAmizades) {
        printf("Nao foi possivel abrir o arquivo de amizades\n");
        return;
    }

    char nome[100];
    while ( fscanf(fAmizades, "%[^;\n]%*c", nome) == 1) {
        Usuario *usuario = CriaUsuario(nome);
        InsereListaUsuario(lista, usuario);
        RetiraListaUsuario(lista, usuario);
    }

    fclose(fAmizades);
}

void InsereListaUsuario(ListaUsuario *lista, Usuario *user) {
    if (!lista || !user) return;

    Celula *c = malloc(sizeof(Celula));
    c->proximo = NULL;
    c->usuario = user;


    lista->ult->proximo = c;
    lista->ult = c;
}

void RetiraListaUsuario(ListaUsuario *lista, Usuario *user) {
    if (!lista || !user || !lista->prim) return;

    Celula *auxiliar = lista->prim, *ant;
    if (auxiliar->usuario == user) {
        lista->prim = lista->prim->proximo;
        LiberaUsuario(auxiliar->usuario);
        free(auxiliar);

        if (!lista->prim) lista->ult = NULL;
        
        return;
    }

    while (auxiliar) {
        // se for o usuario desejado
        if (auxiliar->usuario == user) {
            ant->proximo = auxiliar->proximo;

            // se for o ultimo usuario
            if(auxiliar == lista->ult) 
                lista->ult = ant;

            LiberaUsuario(auxiliar->usuario);
            free(auxiliar);
            return;
        }

        ant = auxiliar;
        auxiliar = auxiliar->proximo;
    }
}

void ImprimeListaUsuario(ListaUsuario *lista) {
    if (!lista) return;

    Celula *auxiliar = lista->prim;
    while (auxiliar) {
        ImprimeUsuario(auxiliar->usuario);
        auxiliar = auxiliar->proximo;
    }
}

void LiberaListaUsuario(ListaUsuario *lista) {
    if (!lista) return;

    Celula *auxiliar = lista->prim;
    while (auxiliar) {
        auxiliar = lista->prim->proximo;
        LiberaUsuario(lista->prim->usuario);
        free(lista->prim);
        lista->prim = auxiliar;
    }

    free(lista);
}