#ifndef _USUARIO_H_
#define _USUARIO_H_

typedef struct Usuario Usuario;

Usuario *CriaUsuario(char *nome);

void LiberaUsuario(Usuario *usuario);

void ImprimeUsuario(Usuario *usuario);

#endif // !_USUARIO_H