#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"
#include "ListaUsuario.h"

#define DIR_MAX_SIZE 1000

int main () {
    ListaUsuario *lista = IniciaListaUsuario();
    ListaAmizade *amizades = CriaListaAmizade();
    
    /**
     * Le os usuarios do sistema e relaciona suas amizades, respectivamente
    */
    FILE *arquivoInicial = LeUsuariosDoArquivo(lista);
    LeArquivoAmizade(arquivoInicial, amizades, lista);

    /**
     * Le e insre as playlists de casa usuario do sistema
     * Em seguida, preenche cada playlist com suas respectivas musicas
    */
    LePlaylistsUsuarios(lista);
    PreenchePlaylistUsuarios(lista);

    /**
     * Analisa cada playlist do usuario e preenche uma lista de playlists com
     * playlists separadas por artistas. Em seguida, gera os arquivos correspondentes
     * para cada pessoa e suas playlists dos artistas
    */
    // SeparaPlaylistArtistasPorUsuario(lista); 
    // ImprimeEmArquivoPlaylistsGlobal(lista);

    /**
     * Cria as demais saidas requisitadas no trabalho:
     * 1 - Cria e preenche a playlist refatorada de cada usuario do sistema
     * 2 - Analisa as similaridades e preenche o arquivo com as similaridades entre amigos
    */ 
    // PlaylistRefatorada(lista);
    // Similaridades(amizades);

    LiberaListaAmizade(amizades);
    LiberaListaUsuario(lista);
    return 0;
}