#ifndef _USUARIO_H_
#define _USUARIO_H

typedef struct Usuario Usuario;

Usuario *CriaUsuario(char *path);

void ImprimeUsuario(Usuario *u);

void LiberaUsuario(Usuario *u);

#endif // !_USUARIO_H_