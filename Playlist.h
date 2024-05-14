#ifndef _PLAYLIST_H_
#define _PLALIST_H_
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Usuario Usuario;
typedef struct Playlist Playlist;
typedef struct ListaPlaylist ListaPlaylist;

typedef struct Celula Celula;

#include"Usuario.h"
#include"Musica.h"



Playlist *CriaPlaylist(char *nome);

ListaPlaylist *CriaListaPlaylist();

void InsereMusicasPlaylist(Playlist *play);

void LiberaPlaylist(Playlist *playlist);

void ImprimePlaylistArquivo(Playlist *playlist);

bool EhIgualPlaylist(char* nome, Playlist *play);

void AnalisaPlaylistsArtistas(Playlist *play, ListaPlaylist *lista, Usuario *usuario);

Playlist *InserePlaylistLista(ListaPlaylist *lista, char *nome);

void InsereMusicaPlaylist(Playlist *play, Musica *musica);

void AnalisaPlaylistsArtistasIndividual(ListaPlaylist *inicial, ListaPlaylist *final, Usuario *usuario);

void PreencheListasPlaylistUsuario(ListaPlaylist *lista);

void ImprimeEmArquivoPlaylistsUsuario(char *nome, ListaPlaylist *playlists);
#endif // !_MUSICA_H