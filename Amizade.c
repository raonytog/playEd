
#include "Amizade.h"

typedef struct Celula Celula;
struct Amizade{
    Usuario *amigo1;
    Usuario *amigo2;
};
struct Celula {
    Amizade *relacao;
    Celula *proximo;
};

struct ListaAmizade {
    Celula *inic, *fim;
};

ListaAmizade *CriaListaAmizade() {
    ListaAmizade *lista = malloc(sizeof(ListaAmizade));
    lista->inic = lista->fim = NULL;
    return lista;
}

void LeArquivoAmizade(FILE *fAmizades, ListaAmizade *amizades, ListaUsuario *lista){
    if(!fAmizades || !lista || !amizades) return;
    char nome[100], nome1[100];
    while (fscanf(fAmizades, "%[^;];%[^\n]%*c", nome, nome1) == 2) {
        Usuario *u1 = AchaUsuarioNome(lista, nome);
        Usuario *u2 = AchaUsuarioNome(lista, nome1);
        if(u1 && u2) {
            Amizade *amgs = CriaAmizade(u1, u2);
            InsereAmizadeLista(amizades, amgs);
        }
    }

    fclose(fAmizades);

}

Amizade *CriaAmizade(Usuario *usuario1, Usuario *usuario2){
    if(!usuario1 || !usuario2) return NULL;

    Amizade *amgs = malloc(sizeof(Amizade));
    if(!amgs) return NULL;
    amgs->amigo1 = usuario1;
    amgs->amigo2 = usuario2;
    return amgs;
}

void InsereAmizadeLista(ListaAmizade *lista, Amizade *amgs) {
    if (!lista || !amgs) return;

    Celula *celula = malloc(sizeof(Celula));
    celula->relacao = amgs;
    celula->proximo = NULL;

    if (!lista->inic && !lista->fim) {
        lista->inic = lista->fim = celula;
        return;
    }

    lista->fim->proximo = celula;
    lista->fim = celula;
}

void LiberaListaAmizade(ListaAmizade *lista) {
    if (!lista) return;

    Celula *auxiliar = lista->inic;
    while (auxiliar) {
        auxiliar = lista->inic->proximo;
        free(lista->inic);
        lista->inic = auxiliar;
    }

    free(lista);
}

void Similaridades(ListaAmizade *lista) {
    if (!lista) return;

    FILE *fSimilaridades = NULL;
    fSimilaridades = fopen("Saidas/similaridades.txt", "w");
    if (!fSimilaridades) {
        printf("Arquivo de similaridades nao foi aberto corretamente!");
        return;
    }

    Celula *celula = lista->inic;
    while (celula) {
        ImprimeSimiladiridade(celula->relacao, fSimilaridades);
        celula = celula->proximo;
    }

    fclose(fSimilaridades);
}

void ImprimeSimiladiridade(Amizade *relacao, FILE *file) {
    if (!relacao) return;

    int qtdMusicasIguais = 0;
    ListaPlaylist *l1 = RetornaListaArtistaUsuario(relacao->amigo1), *l2 = RetornaListaArtistaUsuario(relacao->amigo2);
    qtdMusicasIguais = RetornaRelacaoMusicaAmigos(l1, l2);

    fprintf(file, "%s;%s;%d\n", RetornaNomeUsuario(relacao->amigo1), 
                                RetornaNomeUsuario(relacao->amigo2),
                                qtdMusicasIguais);
}