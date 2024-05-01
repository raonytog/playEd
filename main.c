#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Usuario.h"

#define DIR_MAX_SIZE 1000


int main (int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Diretorio invalido\n");
        exit(EXIT_FAILURE);
    }

    char path[DIR_MAX_SIZE];
    sprintf(path, "%s", argv[1]);

    Usuario *raony = CriaUsuario(path);
    ImprimeUsuario(raony);
    return 0;
}