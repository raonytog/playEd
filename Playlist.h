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


/* Funcoes de retorno */

char *RetornaNomePlaylist(Playlist *playlist);

int RetornaRelacaoMusicaAmigos(ListaPlaylist *artistasP1, ListaPlaylist *artistasP2);

bool EhIgualPlaylist(char* nome, Playlist *play);

/* Funcoes principais do cliente*/

Playlist *CriaPlaylist(char *nome);

ListaPlaylist *CriaListaPlaylist();

void InsereMusicasPlaylist(Playlist *play);

Playlist *InserePlaylistLista(ListaPlaylist *lista, char *nome);

void InsereMusicaPlaylist(Playlist *play, Musica *musica);

void PreencheListasPlaylistUsuario(ListaPlaylist *lista);

void AnalisaPlaylistsArtistas(Playlist *play, ListaPlaylist *lista, Usuario *usuario);

void AnalisaPlaylistsArtistasIndividual(ListaPlaylist *inicial, ListaPlaylist *final, Usuario *usuario);

/* Funcoes de liberar memoria */
void LiberaPlaylist(Playlist *playlist);

void LiberaListaPlaylist(ListaPlaylist *playlist);

void LiberaListaPlaylistArtistas(ListaPlaylist *playlist);

/* Funcoes de impressao */

void ImprimePlaylistArquivo(Playlist *playlist);

void ImprimeEmArquivoPlaylistsUsuario(char *nome, ListaPlaylist *playlists);

void ImprimePlaylistRefatorada(char *nome, int qtdArtistas, ListaPlaylist *playlistArtistas);

#endif