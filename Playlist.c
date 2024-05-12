#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Playlist.h"

typedef struct Celula Celula;
typedef struct CelulaPlay CelulaPlay;

struct Celula {
    Musica *musica;
    Celula *prox;
};

struct Playlist {
    char *nome;
    Celula *prim, *ultima;
};
struct CelulaPlay {
    Playlist *musica;
    Celula *prox;
};
typedef struct ListaPlaylist {
    CelulaPlay *ini;
    CelulaPlay *fim;
} ListaPlaylist;

Playlist *CriaPlaylist(char *nome){
    Playlist *play = malloc(sizeof(Playlist));
    if(!play) return NULL;
    play->nome = strdup(nome);
    play->prim = play->ultima = NULL;
    return play;
}

void InsereMusicasPlaylist(Playlist *play){
    if (!play) return;
    
    char arqPlayNome[100];
    FILE *fPlaylist = NULL;
    sprintf(arqPlayNome, "Entradas/%s", play->nome);
    fPlaylist = fopen(arqPlayNome, "r");
   
    if (!fPlaylist) {
        printf("Nao foi possivel abrir o arquivo de playlist\n");
        return;
    }

    char nomeArt[100], nomeMusica[100];
    Celula *aux = NULL;
    while ( fscanf(fPlaylist, "%[^-]- %[^\n]%*c", nomeArt, nomeMusica) == 2) {
        
        Celula *c = malloc(sizeof(Celula));
        c->musica = CriaMusica(nomeArt, nomeMusica);
        c->prox = NULL;

        if(!play->prim){
            play->prim = play->ultima = c;

        } else{
            play->ultima->prox= c;
            play->ultima = c;
        }
    }

    fclose(fPlaylist);
}

void LiberaPlaylist(Playlist *playlist){
    if(!playlist) return;
    Celula *auxiliar = playlist->prim->prox;
    
    while(auxiliar) {
       auxiliar = playlist->prim->prox;
       LiberaMusica(playlist->prim->musica);
       free(playlist->prim);
       playlist->prim = auxiliar;
    }

    free(playlist->nome);
    free(playlist);
}

void ImprimePlaylistArquivo(Playlist *playlist){
    if (!playlist) return;

    char nomeArq[100];
    sprintf(nomeArq,"saida%s.txt",playlist->nome);
    FILE *fPlaylist = fopen(nomeArq, "w");
    if(!fPlaylist) {
        printf("Arquivo para impressao nao abriu!");
        return;
    }
        
    Celula *aux = playlist->prim;
    while(aux){
        ImprimeMusicaArquivo(aux->musica, fPlaylist);
        aux = aux->prox;
    }  
    fclose(fPlaylist);    
}

void EhIgualPlaylist(char* nome, Playlist *play){
    return (!strcomp(nome, play->nome));
}

void AnalisaPlaylistsArtistas(Playlist *play, ListaPlaylist *lista){
    if(!play) return;
    Celula *aux = play->prim;

    while(aux){
        Musica *m = aux->musica;
        if(lista->ini==NULL){
            Playlist *play = CriaPlaylist(RetornaArtista(m));
        }
        else{
            CelulaPlay *cp = lista->ini;
            while(cp)
                
                if(strcmp(RetornaArtista(m), play->nome)!=0){
            }
        
        }
        
        aux = aux->prox;
    }
}