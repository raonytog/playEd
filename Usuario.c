#include "Usuario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario {
    char *nome;
    int numArtista, numPlaylists;
    // playlist
};

Usuario *CriaUsuario(char *path) {
    if (!path) return NULL;

    char pathUsuarios[1000];
    sprintf(pathUsuarios, "%s/teste.txt", path);

    FILE *fUser = fopen(pathUsuarios, "r");
    if (!fUser) {
        printf("Arquivo de usuarios nao foi aberto!");
        exit(1);
    }

    Usuario *user = malloc(sizeof(Usuario));
    char temp[1000];
    fscanf(fUser, "%[^;];%d;", temp, &user->numPlaylists);
    user->nome = strdup(temp);

    for (int i = 0; i < user->numPlaylists; i++) {
         fscanf(fUser, ";%[^;\n]", temp);
    }
    fscanf(fUser, "\n");

    fclose(fUser);
    return user;
}

void ImprimeUsuario(Usuario *u) {
    if (!u) return;
    printf("%s;%d\n", u->nome, u->numPlaylists);
}

void LiberaUsuario(Usuario *u) {
    if (!u) return;
    free(u->nome);
    free(u);
}

