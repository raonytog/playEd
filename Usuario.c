#include "Usuario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Playlist.h"

typedef struct celulaP celulaP;

typedef struct listaP {
    celulaP *ini;
    celulaP *fim;
}listaP;

struct Usuario {
    char *nome;
    listaP *playlists;
    int numPlaylists;
    // amizades
};



struct celulaP
{
    celulaP *proxima;
    Playlist *p;  
};




Usuario *CriaUsuario(char *nome) {
    if (!nome) return NULL;

    Usuario *pessoa = malloc(sizeof(Usuario));
    if (!pessoa) return NULL;
    pessoa->nome = strdup(nome);
    pessoa->numPlaylists = 0;
    pessoa->playlists = malloc(sizeof(listaP));
    if (!pessoa->nome) {
        free(pessoa);
        return NULL;
    }

    return pessoa;
}

void InserePlaylistUsuario(Usuario *usuario, char *nome){
    if (!usuario || !nome) return;

    Playlist *playlist = CriaPlaylist(nome);
    
    celulaP *celula = malloc(sizeof(celula));
    celula->p = playlist;
    celula->proxima = NULL;

    // lista vazia
    if (!usuario->playlists->ini) {
        usuario->playlists->ini = usuario->playlists->fim = celula;
        return;
    }

    usuario->playlists->fim->proxima = celula;
    usuario->playlists->fim = celula;
}

void InsereNumPlaylistUsuario(Usuario *usuario,int numPlaylist){
    if(usuario){
        usuario->numPlaylists = numPlaylist;
    }
}

void CriaPlaylistsDiferentes(Usuario *usuario);

void LiberaUsuario(Usuario *usuario) {
    if (!usuario) return;
    if (usuario->nome) free(usuario->nome);
    free(usuario);
}

void ImprimeUsuario(Usuario *usuario) {
    printf("Nome: %s\n", usuario->nome);
}

void PreenchePlaylistUsuario(Usuario *usuario){

    celulaP *aux = usuario->playlists->ini;
    while(aux){
        InsereMusicasPlaylist(aux->p);
        aux = aux->proxima;
        
    }
}