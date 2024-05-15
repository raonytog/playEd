#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula Celula;
typedef struct CelulaPlay CelulaPlay;

#include "Usuario.h"

struct Usuario {
    char *nome;
    int numPlaylists, numArtistas;

    ListaPlaylist *playlists;
    ListaPlaylist *playlistsArtistas;

};

Usuario *CriaUsuario(char *nome) {
    if (!nome) return NULL;

    Usuario *pessoa = malloc(sizeof(Usuario));

    pessoa->nome = strdup(nome);
    pessoa->numPlaylists = pessoa->numArtistas = 0;

    pessoa->playlists = CriaListaPlaylist();
    pessoa->playlistsArtistas = CriaListaPlaylist();
    return pessoa;
}

void InserePlaylistUsuario(Usuario *usuario, char *nome, int tipo) {
    if (!usuario || !nome) return;

    if(tipo == 1){
        Playlist *p = InserePlaylistLista(usuario->playlists, nome);
    } 
    //if(tipo == 2) InserePlaylistLista(usuario->playlistsArtistas, nome);
  
}

void InsereNumPlaylistUsuario(Usuario *usuario,int numPlaylist) {
    if(!usuario || numPlaylist < 0) return;
    usuario->numPlaylists = numPlaylist;
}

void LiberaUsuario(Usuario *usuario) {
    if (!usuario) return;
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
    PreencheListasPlaylistUsuario(usuario->playlists);
}
char *RetornaNomeUsuario(Usuario *usuario){
    if(!usuario) return NULL;
    return usuario->nome;
}

int RetornaNumArtistas(Usuario *usuario) {
    if (!usuario) return 0;
    return usuario->numArtistas;
}

int RetornaNumPlaylists(Usuario *usuario) {
    if (!usuario) return 0;
    return usuario->numPlaylists;
}

ListaPlaylist *RetornaListaPlaylistUsuario(Usuario *usuario) {
    if (!usuario) return NULL;
    return usuario->playlists;
}

ListaPlaylist *RetornaListaArtistaUsuario(Usuario *usuario) {
    if (!usuario) return NULL;
    return usuario->playlistsArtistas;
}

void SeparaPlaylist(Usuario *usuario){
    if(!usuario) return;
    AnalisaPlaylistsArtistasIndividual(usuario->playlists, 
                                      usuario->playlistsArtistas, 
                                      usuario);
}

void IncrementaNumeroArtistasUsuario(Usuario *usuario) {
    if (!usuario) return;
    usuario->numArtistas++;
}

