#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Usuario.h"
#include "ListaUsuarios.h"

#define DIR_MAX_SIZE 1000

// int main (int argc, char *argv[]) {
//     if (argc <= 1) {
//         printf("Diretorio invalido\n");
//         exit(EXIT_FAILURE);
//     }
//  char path[DIR_MAX_SIZE];
//  sprintf(path, "%s", argv[1]);


/** MAIN DE TESTE 
 * enquanto nao sei configurar o json 
 * para pegar o path como arg
*/
int main () {
    char path[DIR_MAX_SIZE] = "testes/";

    ListaUsuarios *usuarios = IniciaListaUsuarios();
    LeUsuariosDoArquivo(usuarios, path);
    ImprimeListaUsuario(usuarios);

    LiberaListaUsuario(usuarios);
    return 0;
}