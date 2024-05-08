#ifndef _PLAYLIST_H_
#define _PLALIST_H_
#include<string.h>
#include"Musica.h"

typedef struct Playlist Playlist;

Playlist *CriaPlaylist(char *nome);

void InsereMusicasPlaylist(Playlist *play);

void LiberaPlaylist(Playlist *playlist);

void ImprimePlaylistArquivo(Playlist *playlist);

#endif // !_MUSICA_H