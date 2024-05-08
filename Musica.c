#include"Musica.h"
#include<string.h>
struct Musica{
    char *nome;
    char *artista;
};

Musica *CriaMusica(char *nomeArt, char *nomeMusica){
    Musica *m = calloc(1, sizeof(Musica));
    if(!m){
        printf("Não foi possível cadastrar música");
        return NULL;
    }

    m->artista = strdup(nomeArt);
    m->nome = strdup(nomeMusica);
    return m;
}

void LiberaMusica(Musica *musica){
    if(musica){
        free(musica->nome);
        free(musica->artista);
        free(musica);
    }
}

void ImprimeMusicaArquivo(Musica *music, FILE *arq){
    if(arq && music){
        fprintf(arq,"%s - %s\n", music->artista, music->nome);
    }
}