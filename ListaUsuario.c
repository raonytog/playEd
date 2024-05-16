#include "ListaUsuario.h"
#include <sys/stat.h> 
#include <sys/types.h> 
#include"Amizade.h"
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

FILE *LeUsuariosDoArquivo(ListaUsuario *lista) {
    if (!lista) return NULL;
    
    FILE *fAmizades = NULL;
    fAmizades = fopen("Entradas/amizade.txt", "r");
    if (!fAmizades) {
        printf("Nao foi possivel abrir o arquivo de amizades\n");
        return NULL;
    }

    char nome[100], flag = '\n';
    while ( fscanf(fAmizades, "%[^;\n]%c", nome, &flag) == 2) {
        Usuario *usuario = CriaUsuario(nome);
        InsereListaUsuario(lista, usuario);
        if(flag =='\n') break;
    }

    
    return fAmizades;
}

void LePlaylistsUsuarios(ListaUsuario *lista){
     if (!lista) return;
    
    FILE *fPlaylists = NULL;
    fPlaylists = fopen("Entradas/playlists.txt", "r");
    if (!fPlaylists) {
        printf("Nao foi possivel abrir o arquivo de amizades\n");
        return;
    }

    char nomePessoa[100] = "\0", nomePlaylist[100] = "\0", flag = '\0';
    int numPlaylist = 0;
    Celula *celula = lista->prim;

    while ( fscanf(fPlaylists, "%[^;\n];%d", nomePessoa, &numPlaylist) == 2 && celula) {
        InsereNumPlaylistUsuario(celula->usuario, numPlaylist);
        for (int i = 0; i < numPlaylist; i++) {
            fscanf(fPlaylists, ";%[^;\n]", nomePlaylist);
            InserePlaylistUsuario(celula->usuario, nomePlaylist, 1);
        }
        fscanf(fPlaylists, "%*c");
        celula = celula->proximo;
    }
    
    fclose(fPlaylists);
}

void PreenchePlaylistUsuarios(ListaUsuario *lista){
    Celula *c = lista->prim;
    while (c) {
        PreenchePlaylistUsuario(c->usuario);
        c = c->proximo;
    }
}

void InsereListaUsuario(ListaUsuario *lista, Usuario *user) {
    if (!lista || !user) return;

    Celula *c = malloc(sizeof(Celula));
    c->proximo = NULL;
    c->usuario = user;

    if(!lista->prim){
        lista->prim = lista->ult=c;
        return;
    }
    
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

Usuario *AchaUsuarioNome(ListaUsuario *lista, char *nome){    
    if(!nome || !lista) return NULL;
    if(!strcmp(RetornaNomeUsuario(lista->prim->usuario), nome))   return lista->prim->usuario;
     
    Celula *c = lista->prim->proximo;
    
    while(c){ 
        Usuario *u = c->usuario;
        if(!strcmp(RetornaNomeUsuario(u), nome)) return u;
        c = c->proximo;
    }
    return NULL;
    }

void SeparaPlaylistArtistasPorUsuario(ListaUsuario *lista){
    if(!lista) return;

    Celula *aux = lista->prim;
    while (aux){
        Usuario *usuario = aux->usuario;
        SeparaPlaylist(usuario);
        aux = aux->proximo;
    }
}

void ImprimeEmArquivoPlaylistsGlobal(ListaUsuario *lista){
    if(!lista) return;

    Celula *aux = lista->prim;
    int arq = mkdir("Saidas", 0777);
    if(arq==-1) printf("Erro ao criar diretorios");
    while(aux){
        Usuario *usuario = aux->usuario;
        ImprimeEmArquivoPlaylistsUsuario(RetornaNomeUsuario(usuario),
        RetornaListaArtistaUsuario(usuario));
        aux = aux->proximo;
    }
}

void PlaylistRefatorada(ListaUsuario *lista) {
    if (!lista) return;

    Celula *celula = lista->prim;
    while (celula) {
        ImprimePlaylistRefatorada( RetornaNomeUsuario(celula->usuario), 
                                   RetornaNumArtistas(celula->usuario),
                                   RetornaListaArtistaUsuario(celula->usuario));
        celula = celula->proximo;
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