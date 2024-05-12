#ifndef _USUARIO_H_
#define _USUARIO_H_
typedef struct ListaAmizade ListaAmizade;
#include "Amizade.h"

typedef struct Usuario Usuario;

Usuario *CriaUsuario(char *nome);

void InserePlaylistUsuario(Usuario *usuario, char *nome);

void InsereNumPlaylistUsuario(Usuario *usuario,int numPlaylist);

void LiberaUsuario(Usuario *usuario);

void ImprimeUsuario(Usuario *usuario);

void PreenchePlaylistUsuario(Usuario *usuario);

char *RetornaNomeUsuario(Usuario *usuario);

ListaAmizade *RetornaListaAmizade(Usuario *usuario);

#endif // !_USUARIO_H