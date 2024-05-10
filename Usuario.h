#ifndef _USUARIO_H_
#define _USUARIO_H_

typedef struct Usuario Usuario;

Usuario *CriaUsuario(char *nome);

void InserePlaylistUsuario(Usuario *usuario, char *nome);

void InsereNumPlaylistUsuario(Usuario *usuario,int numPlaylist);


void LiberaUsuario(Usuario *usuario);

void ImprimeUsuario(Usuario *usuario);

void PreenchePlaylistUsuario(Usuario *usuario);

#endif // !_USUARIO_H