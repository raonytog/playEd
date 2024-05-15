#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Playlist.h"
#include <sys/stat.h> 
#include <sys/types.h> 
typedef struct Celula Celula;
typedef struct CelulaPlay CelulaPlay;

/* playlist de musicas */
struct Celula {
    Musica *musica;
    Celula *prox;
};

struct Playlist {
    char *nome;
    Celula *prim, *ultima;
};

/* lista de playlists*/
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
        nomeArt[strlen(nomeArt) - 1] = '\0'; // retira espaco armazenado 
        
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

// playlist normal, playlist artista
void AnalisaPlaylistsArtistasIndividual(ListaPlaylist *inicial, ListaPlaylist *final, Usuario *usuario) {
    if(!inicial) return;
    
    CelulaPlay *celula = inicial->ini;
    while(celula){
        AnalisaPlaylistsArtistas(celula->p, final, usuario);
        celula = celula->proxima;
    }
}

void InsereMusicaPlaylist(Playlist *play, Musica *musica){
    if(!play || !musica) return;
     
    Celula *celula = malloc(sizeof(Celula));
    celula->musica = musica;
    celula->prox = NULL;

    if(!play->prim){
        play->prim = play->ultima = celula;

    } else{
        play->ultima->prox= celula;
        play->ultima = celula;
    }

}
// normal, artista
void AnalisaPlaylistsArtistas(Playlist *play, ListaPlaylist *lista, Usuario *usuario){
    if(!play) return;
    Celula *aux = play->prim;
    Celula* aux2= NULL;

    int musicaRepetida = 0;
    
    while(aux){
        Musica *m = aux->musica;
        aux2 = aux;
        aux = aux->prox;
        int flag = 0;

        // se a lista de artista estiver vazia
        if(lista->ini == NULL){
            Playlist *play = InserePlaylistLista(lista, RetornaArtista(m));
            InsereMusicaPlaylist(play, m);
            IncrementaNumeroArtistasUsuario(usuario);
            flag++;

        // caso n esteja vazia, procura a pessoa
        } else {
            CelulaPlay *cp = lista->ini;
            while(cp){
                Playlist *play = cp->p;
                if(strcmp(RetornaArtista(m), play->nome)==0) { 
                    Celula *musica = play->prim;
                    while (musica) {
                        if (strcmp(RetornaMusica(m), RetornaMusica(musica->musica)) == 0) musicaRepetida = 1;
                        musica = musica->prox;
                        break;
                    }
                    if (!musicaRepetida) InsereMusicaPlaylist(play, m);
                    flag++;
                }
              
                cp = cp->proxima;
            }
        
            // caso nao ache a pessoa
            if(!flag) {
                Playlist *play = InserePlaylistLista(lista,RetornaArtista(m));
                InsereMusicaPlaylist(play, m);
                IncrementaNumeroArtistasUsuario(usuario);
            } 
        }
    }
}

Playlist *InserePlaylistLista(ListaPlaylist *lista, char *nome) {
    if (!lista || !nome) return NULL;

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


void ImprimeEmArquivoPlaylistsUsuario(char *nome, ListaPlaylist *playlists) {
    if(!nome || !playlists) return;

    CelulaPlay *aux = playlists->ini;
    char caminho1[150], caminho[200];
    sprintf(caminho1, "Saidas/%s", nome);

    int arq = mkdir(caminho1, 0777);
    if(arq==-1) printf("Erro ao criar diretorios");

    while(aux) {
        sprintf(caminho, "%s/%s.txt", caminho1, aux->p->nome);
        FILE *arquivoPlaylist = fopen(caminho, "w");
        if(!arquivoPlaylist) return;

        Celula *musicas = aux->p->prim;
        while (musicas) {
            ImprimeMusicaArquivo(musicas->musica, arquivoPlaylist);
            musicas = musicas->prox;
        }
        
        fclose(arquivoPlaylist);
        aux = aux->proxima;
    }
}

void ImprimePlaylistRefatorada(char *nome, int qtdArtistas, ListaPlaylist *playlistArtistas) {
    FILE *fFatorada = NULL;
    fFatorada = fopen("Saidas/played-fatorada.txt", "a+");
    if (!fFatorada) {
        printf("Arquivo de saida da playlist-fatorada nao aberto");
        return;
    }

    fprintf(fFatorada, "%s;%d", nome, qtdArtistas);
    CelulaPlay *celula = playlistArtistas->ini;
    while (celula) {
        fprintf(fFatorada, ";%s.txt", RetornaNomePlaylist(celula->p));
        celula = celula->proxima;
    }
    fprintf(fFatorada, "\n");

    fclose(fFatorada);
}

char *RetornaNomePlaylist(Playlist *playlist) {
    if (!playlist) return '\0';
    return playlist->nome;
}

int RetornaRelacaoMusicaAmigos(ListaPlaylist *artistasP1, ListaPlaylist *artistasP2) {
    if (!artistasP1 || !artistasP2) return -1;

    int qtdMusicasIguaisTotais = 0;
    for (CelulaPlay *i = artistasP1->ini; i; i = i->proxima) {
        for (CelulaPlay *j = artistasP2->ini; j; j = j->proxima) {
            if (strcmp(RetornaNomePlaylist(i->p), RetornaNomePlaylist(j->p)) == 0) {
                for (Celula *m = i->p->prim; m; m = m->prox) {
                    for (Celula *n = j->p->prim; n; n = n->prox) {
                        if (strcmp(RetornaMusica(m->musica), RetornaMusica(n->musica)) == 0)
                            qtdMusicasIguaisTotais++;
                    }
                }
            }
        }
    }

    return qtdMusicasIguaisTotais;
}