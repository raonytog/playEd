#ifndef _USUARIO_H_
#define _USUARIO_H_

typedef struct Playlist Playlist;
typedef struct ListaAmizade ListaAmizade;

#include "Playlist.h"
#include "Amizade.h"

typedef struct Usuario Usuario;

Usuario *CriaUsuario(char *nome);

void InserePlaylistUsuario(Usuario *usuario, char *nome, int tipo);

void InsereNumPlaylistUsuario(Usuario *usuario,int numPlaylist);

void LiberaUsuario(Usuario *usuario);

void ImprimeUsuario(Usuario *usuario);

void PreenchePlaylistUsuario(Usuario *usuario);

char *RetornaNomeUsuario(Usuario *usuario);

int RetornaNumArtistas(Usuario *usuario);

int RetornaNumPlaylists(Usuario *usuario);

ListaPlaylist *RetornaListaPlaylistUsuario(Usuario *usuario);

ListaPlaylist *RetornaListaArtistaUsuario(Usuario *usuario);

void IncrementaNumeroArtistasUsuario(Usuario *usuario);

void SeparaPlaylist(Usuario *Usuario);

#endif // !_USUARIO_H