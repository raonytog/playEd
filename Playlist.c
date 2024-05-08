#include"Playlist.h"
#include<stdlib.h>
#include<stdio.h>
typedef struct celula celula;

struct celula
{   Musica *musica;
    celula *prox;
};

struct Playlist {
    char *nome;
    celula *prim;
    celula *ultima; 
};

Playlist *CriaPlaylist(char *nome){
    Playlist *play = calloc(1, sizeof(Playlist));
    if(!play) return NULL;
    play->nome = strdup(nome);
    return play;
}

void InsereMusicasPlaylist(Playlist *play){
    if (!play) return;
    
    char arqPlayNome[100];
    FILE *fPlaylist = NULL;
    sprintf(arqPlayNome, "%s.txt", play->nome);
    fPlaylist = fopen(arqPlayNome, "r");
   
    if (!fPlaylist) {
        printf("Nao foi possivel abrir o arquivo de playlist\n");
        return;
    }

    char nomeArt[100], nomeMusica[100];
    celula *aux = NULL;
    while ( fscanf(fPlaylist, "%[^-]- %[^\n]%*c", nomeArt, nomeMusica) == 2) {
        
        celula *c = calloc(1, sizeof(celula));
        c->musica = CriaMusica(nomeArt, nomeMusica);
        c->prox = NULL;

        if(!play->prim){
            play->prim = play->ultima = c;
        }
       
        else{
    
            play->ultima->prox= c;
            play->ultima = c;
        }
       
    }

    fclose(fPlaylist);
    
}

void LiberaPlaylist(Playlist *playlist){
    if(!playlist) return;
    celula *aux = playlist->prim->prox;
    
    while(aux){
       aux =  playlist->prim->prox;
       LiberaMusica(playlist->prim->musica);
       free(playlist->prim);
       playlist->prim = aux;
    }
    free(playlist->nome);
    free(playlist);
}

void ImprimePlaylistArquivo(Playlist *playlist){
    if(playlist){
        char nomeArq[100];
        sprintf(nomeArq,"saida%s.txt",playlist->nome);
        FILE *playlistArq = fopen(nomeArq, "w");
        if(playlistArq){
            
            celula *aux = playlist->prim;
            while(aux){
                ImprimeMusicaArquivo(aux->musica, playlistArq);
                aux = aux->prox;
            }  
            fclose(playlistArq);    
        } 
    }
}

