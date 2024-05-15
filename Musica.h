#ifndef _MUSIC_H_
#define _MUSIC_H_
#include<stdlib.h>
#include<stdio.h>
typedef struct Musica Musica;

/* Funcoes de retorno */
char *RetornaMusica(Musica *music);

char *RetornaArtista(Musica *music);

/* Funcoes principais do cliente */
Musica *CriaMusica(char *nomeArt, char *nomeMusica);

void LiberaMusica(Musica *music);

/* Funcoes de impressao */
void ImprimeMusicaArquivo(Musica *music, FILE *arq);

#endif // !_MUSICA_H