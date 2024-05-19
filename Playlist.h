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
///@brief Retorna o nome de uma playlist
///@param playlist valida
///@return nome da playlist

char *RetornaNomePlaylist(Playlist *playlist);

///@brief Retorna a quantidade de musicas iguais entre dois amigos
///@param lista_artistas_amg1 valida
///@param lista_artistas_amg2 valida
///@return numero de musicas iguais
int RetornaRelacaoMusicaAmigos(ListaPlaylist *artistasP1, ListaPlaylist *artistasP2);

///@brief verifica se duas duas playlists sao iguais pelo nome delas
///@param nome_da_playlist valido
///@param estrutura_Playlist valida
///@return verdadeiro ou falso
bool EhIgualPlaylist(char* nome, Playlist *play);

/* Funcoes principais do cliente*/

///@brief Cria, aloca e retorna uma playlist
///@param nome valido
///@return playlist
Playlist *CriaPlaylist(char *nome);

///@brief Cria, aloca e retorna uma  lista de playlists
///@return lista de playlists
ListaPlaylist *CriaListaPlaylist();

///@brief faz a leitura do arquvo de mesmo nome da playlist e insere as musicas dentro dela
///@param playlist valida
void InsereMusicasPlaylist(Playlist *play);

///@brief coloca na lista uma nova playlist e a retorna
///@param estrutura_Playlist valida
///@param nome valido
///@return playlist
Playlist *InserePlaylistLista(ListaPlaylist *lista, char *nome);

///@brief coloca uma musica já criada dentro de uma playlist
///@param estrutura_Playlist valida
///@param nome valido
void InsereMusicaPlaylist(Playlist *play, Musica *musica);

///@brief preenche toda a lista de playlists
///@param lista_de_Playlist valida
void PreencheListasPlaylistUsuario(ListaPlaylist *lista);

///@brief agrupa as músicas das playlists originais em playlists de artistas
///@param playlist valida
///@param Lista_Playlist valida
///@param usuario valido
void AnalisaPlaylistsArtistas(Playlist *play, ListaPlaylist *lista, Usuario *usuario);

///@brief separa cada uma das playlist originais para fazer o processo de separacao por artista
///@param playlist valida
///@param estrutura_Playlist valida
///@param usuario valido
void AnalisaPlaylistsArtistasIndividual(ListaPlaylist *inicial, ListaPlaylist *final, Usuario *usuario);

/* Funcoes de liberar memoria */
/// @brief Libera a playlist musica
/// @param playlist valida
void LiberaPlaylist(Playlist *playlist);

/// @brief Libera a estrutura lista playlist
/// @param Lista_Playlist valida
void LiberaListaPlaylist(ListaPlaylist *playlist);

/// @brief Libera a estrutura lista playlist inicial no meio do programa
/// @param Lista_Playlist valida
void LiberaListaPlaylistArtistas(ListaPlaylist *playlist);

/* Funcoes de impressao */
/// @brief Imprime a playlist no arquivo no formato, listando todas as musicas da mesma
/// @param playlist valida
void ImprimePlaylistArquivo(Playlist *playlist);

/// @brief chama a impressao de todas as playlists de um usuario 
/// @param nome valido
/// @param ListaPlaylist valida
void ImprimeEmArquivoPlaylistsUsuario(char *nome, ListaPlaylist *playlists);

/// @brief faz impressao do arquivo de refatoradas
/// @param nome valido
/// @param qtdArtista>=0
/// @param ListaPlaylist valida
void ImprimePlaylistRefatorada(char *nome, int qtdArtistas, ListaPlaylist *playlistArtistas, FILE *file);

#endif