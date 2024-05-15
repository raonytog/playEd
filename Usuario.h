#ifndef _USUARIO_H_
#define _USUARIO_H_

typedef struct Playlist Playlist;
typedef struct ListaAmizade ListaAmizade;

#include "Playlist.h"
#include "Amizade.h"

typedef struct Usuario Usuario;

/* Funcoes que modificam os atributos do Usuario */

char *RetornaNomeUsuario(Usuario *usuario);

int RetornaNumArtistas(Usuario *usuario);

int RetornaNumPlaylists(Usuario *usuario);

void IncrementaNumeroArtistasUsuario(Usuario *usuario);

ListaPlaylist *RetornaListaPlaylistUsuario(Usuario *usuario);

ListaPlaylist *RetornaListaArtistaUsuario(Usuario *usuario);

/* Funcoes principais do cliente*/

Usuario *CriaUsuario(char *nome);

void InserePlaylistUsuario(Usuario *usuario, char *nome, int tipo);

void InsereNumPlaylistUsuario(Usuario *usuario,int numPlaylist);

void LiberaUsuario(Usuario *usuario);

void PreenchePlaylistUsuario(Usuario *usuario);

void SeparaPlaylist(Usuario *Usuario);

/* Funcoes de impressao */
void ImprimeUsuario(Usuario *usuario);




#endif // !_USUARIO_H