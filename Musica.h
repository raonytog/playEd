#ifndef _MUSIC_H_
#define _MUSIC_H_
#include<stdlib.h>
#include<stdio.h>
typedef struct Musica Musica;

/* Funcoes de retorno */

/// @brief Retorna o nome da musica
/// @param musica valida
/// @return nome da musica
char *RetornaMusica(Musica *music);

/// @brief Retorna o nome do artista da musica dada
/// @param musica valida
/// @return nome do artista
char *RetornaArtista(Musica *music);

/* Funcoes principais do cliente */

/// @brief A partir do nome do artista e da musica, cria uma musica valida
/// @param nome_do_artista valido
/// @param nome_da_musica valido
/// @return musica valida
Musica *CriaMusica(char *nomeArt, char *nomeMusica);

/* Funcoes de liberar memoria */

/// @brief Libera a estrutura musica
/// @param musica valida
void LiberaMusica(Musica *music);

/* Funcoes de impressao */

/// @brief Imprime a musica no arquivo no formato
/// nome do artista - nome da musica
/// @param musica valida
/// @param arquivo valido
void ImprimeMusicaArquivo(Musica *music, FILE *arq);

#endif // !_MUSICA_H