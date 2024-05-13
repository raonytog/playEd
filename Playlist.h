#ifndef _PLAYLIST_H_
#define _PLALIST_H_
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

void AnalisaPlaylistsArtistas(Playlist *play, ListaPlaylist *lista);

Playlist *InserePlaylistLista(ListaPlaylist *lista, char *nome);

void InsereMusicaPlaylist(Playlist *play, Celula *c);

void AnalisaPlaylistsArtistasIndividual(ListaPlaylist *inicial, ListaPlaylist *final);

void PreencheListasPlaylistUsuario(ListaPlaylist *lista);

#endif // !_MUSICA_H