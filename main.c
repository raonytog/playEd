#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Usuario.h"
#include "ListaUsuario.h"

#define DIR_MAX_SIZE 1000

int main () {
    ListaUsuario *lista = IniciaListaUsuario();
  
    LeUsuariosDoArquivo(lista);
    LePlaylistsUsuarios(lista);
    PreenchePlaylistUsuarios(lista);
  
    ImprimeListaUsuario(lista);
    LiberaListaUsuario(lista);
    return 0;
}