#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"
#include "ListaUsuario.h"

#define DIR_MAX_SIZE 1000

int main () {
    ListaUsuario *lista = IniciaListaUsuario();
    ListaAmizade *amizades = CriaListaAmizade();
    FILE *arquivoInicial = LeUsuariosDoArquivo(lista); // le e relaciona usuarios
    LeArquivoAmizade(arquivoInicial, amizades, lista);
    LePlaylistsUsuarios(lista); // le as playlists
    PreenchePlaylistUsuarios(lista); // insere as musicas
    SeparaPlaylistArtistasPorUsuario(lista); // cria playlist por artista
    ImprimeEmArquivoPlaylistsGlobal(lista);
    ImprimeListaUsuario(lista);
    LiberaListaUsuario(lista);
    return 0;
}