#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Celula Celula;
typedef struct CelulaPlay CelulaPlay;
#include "Usuario.h"


/*struct CelulaPlay {
    CelulaPlay *proxima;
    Playlist *p;  
};

typedef struct ListaPlaylist {
    CelulaPlay *ini;
    CelulaPlay *fim;
} ListaPlaylist;
*/
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

    pessoa->playlists = CriaListaPlaylist();
    pessoa->playlistsArtistas =CriaListaPlaylist();

    pessoa->amigos = CriaListaAmizade();
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

void CriaPlaylistsDiferentes(Usuario *usuario);

void LiberaUsuario(Usuario *usuario) {
    if (!usuario) return;

    /*if (usuario->playlists->ini) {
        CelulaPlay *celula = usuario->playlists->ini->proxima;
        LiberaPlaylist(usuario->playlists->ini->p);
        free(usuario->playlists->ini);
        usuario->playlists->ini = celula;
    }*/

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
ListaAmizade *RetornaListaAmizade(Usuario *usuario) {
    if (!usuario) return NULL;
    return usuario->amigos;
}

 void SeparaPlaylist(Usuario *usuario){
    if(!usuario) return;
    AnalisaPlaylistsArtistasIndividual(usuario->playlists, usuario->playlistsArtistas);

 }