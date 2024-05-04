#include "Usuario.h"

#include <stdlib.h>
#include <string.h>

struct Usuario {
    char *nome;
    int numArtista, numPlaylists;
    // playlist
};

Usuario *CriaUsuario(FILE *fUser) {
    if (!fUser) return NULL;

    Usuario *user = malloc(sizeof(Usuario));
    char temp[1000];
    fscanf(fUser, "%[^;];%d", temp, &user->numPlaylists);
    user->nome = strdup(temp);

    for (int i = 0; i < user->numPlaylists; i++) {
         fscanf(fUser, ";%[^;\n]", temp);
    }
    
    fscanf(fUser, "\n");
    return user;
}

void ImprimeUsuario(Usuario *user) {
    if (!user) return;
    printf("%s;%d\n", user->nome, user->numPlaylists);
}

void LiberaUsuario(Usuario *user) {
    if (!user) return;
    free(user->nome);
    free(user);
}

