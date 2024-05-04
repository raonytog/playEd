#ifndef _USUARIO_H_
#define _USUARIO_H

#include <stdio.h>

typedef struct Usuario Usuario;

Usuario *CriaUsuario(FILE *fUser);

void ImprimeUsuario(Usuario *user);

void LiberaUsuario(Usuario *user);

#endif // !_USUARIO_H_