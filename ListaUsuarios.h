#ifndef _LISTAUSUARIOS_H_
#define _LISTAUSUARIOS_H_

#include "Usuario.h"

typedef struct ListaUsuarios ListaUsuarios;

ListaUsuarios *IniciaListaUsuarios();


void InsereListaUsuario(ListaUsuarios *userList, Usuario *user);

void RetiraListaUsuario(ListaUsuarios *userList, Usuario *user);

void ImprimeListaUsuario(ListaUsuarios *userList);

void LiberaListaUsuario(ListaUsuarios *userList);

int EhListaUsuarioVazia(ListaUsuarios *userList);




#endif // !_LISTAUSUARIOS_H_