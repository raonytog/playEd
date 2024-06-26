#ifndef _LISTAUSUARIO_H_
#define _LISTAUSUARIO_H_
#include<stdlib.h>
#include<stdio.h>
#include "Usuario.h"

typedef struct ListaUsuario ListaUsuario;

/* Funcoes principais do cliente */

ListaUsuario *IniciaListaUsuario();

FILE *LeUsuariosDoArquivo(ListaUsuario *lista);

void LePlaylistsUsuarios(ListaUsuario *lista);

void PreenchePlaylistUsuarios(ListaUsuario *lista);

void InsereListaUsuario(ListaUsuario *lista, Usuario *user);

void RetiraListaUsuario(ListaUsuario *lista, Usuario *user);

void ImprimeListaUsuario(ListaUsuario *lista);

Usuario *AchaUsuarioNome(ListaUsuario *lista, char *nome);

void SeparaPlaylistArtistasPorUsuario(ListaUsuario *lista);

void PlaylistRefatorada(ListaUsuario *lista);

/* Funcoes de impressao */

void ImprimeEmArquivoPlaylistsGlobal(ListaUsuario *lista);


/* Funcoes de liberar memoria */

void LiberaListaUsuario(ListaUsuario *lista);

#endif // !_LISTAUSUARIO_H_