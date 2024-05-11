#ifndef _LISTAUSUARIO_H_
#define _LISTAUSUARIO_H_

#include "Usuario.h"

typedef struct ListaUsuario ListaUsuario;

ListaUsuario *IniciaListaUsuario();

void LeUsuariosDoArquivo(ListaUsuario *lista);

void LePlaylistsUsuarios(ListaUsuario *lista);

void PreenchePlaylistUsuarios(ListaUsuario *lista);

void InsereListaUsuario(ListaUsuario *lista, Usuario *user);

void RetiraListaUsuario(ListaUsuario *lista, Usuario *user);

void ImprimeListaUsuario(ListaUsuario *lista);

Usuario *AchaUsuarioNome(ListaUsuario *lista, char *nome);

void SeparaPlaylistArtistasPorUsuario(ListaUsuario *lista);

void LiberaListaUsuario(ListaUsuario *lista);

#endif // !_LISTAUSUARIO_H_