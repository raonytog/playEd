#ifndef _USUARIO_H_
#define _USUARIO_H_

typedef struct Playlist Playlist;
typedef struct ListaAmizade ListaAmizade;

#include "Playlist.h"
#include "Amizade.h"

typedef struct Usuario Usuario;

/* Funcoes que modificam os atributos do Usuario */

/// @brief Recebe um usuario e, caso valido, retorna o ponteiro para o nome dele
/// @param usuario valido
/// @return nome do usuario
char *RetornaNomeUsuario(Usuario *usuario);

/// @brief Retorna o numero de playlist de artistas do usuario
/// @param usuario valido
/// @return numero de playlists de artistas
int RetornaNumArtistas(Usuario *usuario);

/// @brief Retorna o numero de playlists normais do usuario
/// @param usuario valido
/// @return numero de playlists de normais
int RetornaNumPlaylists(Usuario *usuario);

/// @brief Incrementa o numero de artistas que o usuario possui
/// @param usuario valido
void IncrementaNumeroArtistasUsuario(Usuario *usuario);


/// @brief Retorna uma lista das playlists normais do usuario
/// @param usuario valido
/// @return lista de playlists normais
ListaPlaylist *RetornaListaPlaylistUsuario(Usuario *usuario);


/// @brief Retorna uma lista das playlists dos artistas do usuario
/// @param usuario valido
/// @return lista de playlists de artistas
ListaPlaylist *RetornaListaArtistaUsuario(Usuario *usuario);

/* Funcoes principais do cliente*/


/// @brief Cria um usuario valido
/// @param nome valido
/// @return usuario criado
Usuario *CriaUsuario(char *nome);


void InserePlaylistUsuario(Usuario *usuario, char *nome, int tipo);

/// @brief Insere o numero de playlists dentro do usuario
/// @param usuario valido
/// @param numero_playlist valido
void InsereNumPlaylistUsuario(Usuario *usuario,int numPlaylist);


void PreenchePlaylistUsuario(Usuario *usuario);


void SeparaPlaylist(Usuario *Usuario);

/* Funcoes de liberar memoria */

/// @brief Libera o usuario
/// @param usuario valido
void LiberaUsuario(Usuario *usuario);

/* Funcoes de impressao */

/// @brief Imprime apenas o nome do usuario
/// @param usuario valido
void ImprimeUsuario(Usuario *usuario);

#endif // !_USUARIO_H