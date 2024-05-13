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
    CelulaPlay *proxima;
    Playlist *p;  
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
ListaPlaylist *CriaListaPlaylist(){
    ListaPlaylist *play = malloc(sizeof(ListaPlaylist));
    if(!play) return NULL;
    play->ini = play->fim = NULL;
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

bool EhIgualPlaylist(char* nome, Playlist *play){
    return (!strcmp(nome, play->nome));
}

void AnalisaPlaylistsArtistasIndividual(ListaPlaylist *inicial, ListaPlaylist *final){
    if(!inicial) return;
    CelulaPlay *c = inicial->ini;
    while(c){
        AnalisaPlaylistsArtistas(c->p, final);
        c = c->proxima;
    }
}

void InsereMusicaPlaylist(Playlist *play, Celula *c){
    if(!play || !c) return;
     
     c->prox = NULL;

    if(!play->prim){
        play->prim = play->ultima = c;

    } else{
        play->ultima->prox= c;
        play->ultima = c;
    }

}
void AnalisaPlaylistsArtistas(Playlist *play, ListaPlaylist *lista){
    if(!play) return;
    Celula *aux = play->prim;
    Celula* aux2= NULL;
    
    while(aux){
        Musica *m = aux->musica;
        aux2 = aux;
        aux = aux->prox;
        int flag = 0;

        if(lista->ini==NULL){
            Playlist *play = InserePlaylistLista(lista,RetornaArtista(m));
            InsereMusicaPlaylist(play, aux2);
            flag++;
        }
        else{

                CelulaPlay *cp = lista->ini;
                while(cp){

                    Playlist *play = cp->p;
                    if(strcmp(RetornaArtista(m), play->nome)==0){
                       
                        InsereMusicaPlaylist(play, aux2);
                        flag++;

                }
              
              
          cp = cp->proxima;
        }
        
         if(!flag){

                    Playlist *play = InserePlaylistLista(lista,RetornaArtista(m));
                    InsereMusicaPlaylist(play, aux2);
                    flag++;
        } 
    }
}
}



Playlist *InserePlaylistLista(ListaPlaylist *lista, char *nome) {
    if (!lista || !nome) return;

    Playlist *playlist = CriaPlaylist(nome);
    CelulaPlay *celula = malloc(sizeof(CelulaPlay));
    celula->p = playlist;
    celula->proxima = NULL;

    // lista vazia
    if (!lista->ini && !lista->fim) {
        lista->ini = lista->fim = celula;
        
    }
    else{
        lista->fim->proxima = celula;
        lista->fim = celula;
    }
   
   
   return playlist;
}



void PreencheListasPlaylistUsuario(ListaPlaylist *lista){
    if (!lista) return;
    CelulaPlay *aux = lista->ini;
    while(aux){
        InsereMusicasPlaylist(aux->p);
        aux = aux->proxima;
    }
}