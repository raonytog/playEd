#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Usuario.h"
#include "Playlist.h"

typedef struct Celula Celula;

struct Celula {
    Celula *proxima;
    Playlist *p;  
};

typedef struct ListaPlaylist {
    Celula *ini;
    Celula *fim;
} ListaPlaylist;

struct Usuario {
    char *nome;
    int numPlaylists;
    ListaPlaylist *playlists;
    ListaPlaylist *playlistsArtistas;
    ListaAmizade *amigos;
};

Usuario *CriaUsuario(char *nome) {
    if (!nome) return NULL;

    Usuario *pessoa = malloc(sizeof(Usuario));

    pessoa->nome = strdup(nome);
    pessoa->numPlaylists = 0;

    pessoa->playlists = malloc(sizeof(ListaPlaylist));
    pessoa->playlistsArtistas = malloc(sizeof(ListaPlaylist));
    pessoa->playlists->ini = pessoa->playlists->fim = NULL;

    pessoa->amigos = CriaListaAmizade();
    return pessoa;
}

void InserePlaylistUsuario(Usuario *usuario, char *nome) {
    if (!usuario || !nome) return;

    Playlist *playlist = CriaPlaylist(nome);
    Celula *celula = malloc(sizeof(Celula));
    celula->p = playlist;
    celula->proxima = NULL;

    // lista vazia
    if (!usuario->playlists->ini && !usuario->playlists->fim) {
        usuario->playlists->ini = usuario->playlists->fim = celula;
        return;
    }

    usuario->playlists->fim->proxima = celula;
    usuario->playlists->fim = celula;
}

void InsereNumPlaylistUsuario(Usuario *usuario,int numPlaylist) {
    if(!usuario || numPlaylist < 0) return;
    usuario->numPlaylists = numPlaylist;
}

void CriaPlaylistsDiferentes(Usuario *usuario);

void LiberaUsuario(Usuario *usuario) {
    if (!usuario) return;

    if (usuario->playlists->ini) {
        Celula *celula = usuario->playlists->ini->proxima;
        LiberaPlaylist(usuario->playlists->ini->p);
        free(usuario->playlists->ini);
        usuario->playlists->ini = celula;
    }

    free(usuario->playlists);
    free(usuario->nome);
    free(usuario);
}

void ImprimeUsuario(Usuario *usuario) {
    if (!usuario) return;
    printf("Nome: %s\n", usuario->nome);
}

void PreenchePlaylistUsuario(Usuario *usuario){
    if (!usuario) return;
    Celula *aux = usuario->playlists->ini;
    while(aux){
        InsereMusicasPlaylist(aux->p);
        aux = aux->proxima;
    }
}
char *RetornaNomeUsuario(Usuario *usuario){
    if(!usuario) return NULL;
    return usuario->nome;
}
ListaAmizade *RetornaListaAmizade(Usuario *usuario) {
    if (!usuario) return NULL;
    return usuario->amigos;
}

 void SeparaPlaylist(Usuario *usuario){
    if(!usuario) return;
    Celula *c = usuario->playlists->ini;
    while(c){
        
    }

 }