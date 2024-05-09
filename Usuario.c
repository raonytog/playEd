#include "Usuario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Playlist.h"
struct Usuario {
    char *nome;
    listaP playlists;
    int numPlaylists;
    // amizades
};

typedef struct celulaP celulaP;

struct celulaP
{
    celulaP *proxima;
    Playlist *p;  
};

typedef struct listaP {
    celulaP *ini;
    celulaP *fim;
}listaP;


Usuario *CriaUsuario(char *nome) {
    if (!nome) return NULL;

    Usuario *pessoa = malloc(sizeof(Usuario));
    if (!pessoa) return NULL;

    pessoa->nome = strdup(nome);
    pessoa->numPlaylists = 0;
    if (!pessoa->nome) {
        free(pessoa);
        return NULL;
    }

    return pessoa;
}
void InserePlaylistUsuario(Usuario *usuario){
    
}
void InsereNumPlaylistUsuario(Usuario *usuario,int numPlaylist){
    if(usuario){
        usuario->numPlaylists = numPlaylist;
    }
}
void CriaPlaylistsDiferentes(Usuario *usua);
void LiberaUsuario(Usuario *usuario) {
    if (!usuario) return;
    if (usuario->nome) free(usuario->nome);
    free(usuario);
}

void ImprimeUsuario(Usuario *usuario) {
    printf("Nome: %s\n", usuario->nome);
}