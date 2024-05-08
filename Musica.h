#ifndef _MUSIC_H_
#define _MUSIC_H_
#include<stdlib.h>
#include<stdio.h>
typedef struct Musica Musica;

Musica *CriaMusica(char *nomeArt, char *nomeMusica);

void LiberaMusica(Musica *music);

void ImprimeMusicaArquivo(Musica *music, FILE *arq);

#endif // !_MUSICA_H