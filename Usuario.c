#include "Usuario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario {
    char *nome;
    // playlists
    // amizades
};

Usuario *CriaUsuario(char *nome) {
    if (!nome) return NULL;

    Usuario *pessoa = malloc(sizeof(Usuario));
    if (!pessoa) return NULL;

    pessoa->nome = strdup(nome);
    if (!pessoa->nome) {
        free(pessoa);
        return NULL;
    }

    return pessoa;
}

void LiberaUsuario(Usuario *usuario) {
    if (!usuario) return;
    if (usuario->nome) free(usuario->nome);
    free(usuario);
}

void ImprimeUsuario(Usuario *usuario) {
    printf("Nome: %s\n", usuario->nome);
}