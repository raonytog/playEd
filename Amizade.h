#ifndef AMIZADE_H_
#define AMIZADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Usuario Usuario;
#include "Usuario.h"
typedef struct ListaUsuario ListaUsuario;
#include "ListaUsuario.h"

typedef struct ListaAmizade ListaAmizade;
typedef struct Amizade Amizade;

/* Funcoes principais do cliente */

ListaAmizade *CriaListaAmizade();

/// @brief Le e atribui as relacoes de amizade do arquivo para a lista de amizades
/// @param arquivo_amizades valido
/// @param lista_amizade valida
/// @param lista_usuario valida
void LeArquivoAmizade(FILE *fAmizades, ListaAmizade *amizades, ListaUsuario *lista);


/// @brief Cria uma relacao de amizade entre o usuario 1 e usuario 2
/// @param usuario1 valido
/// @param usuario2 valido
/// @return Amizade entre o usuario 1 e usuario 2
Amizade *CriaAmizade(Usuario *usuario1, Usuario *usuario2);


/// @brief Insere a relacao de amizade a lista de amizade
/// @param lista_amizade valida
/// @param relacao_amizade valida
void InsereAmizadeLista(ListaAmizade *lista, Amizade *amgs);


/// @brief Percorre a lista de amizades e chama a funcao ImprimeSimiladiridade
/// para imprimir no arquivo criado na funcao
/// @param lista_amizade valida
void Similaridades(ListaAmizade *lista);

/* Funcoes de liberar memoria */

/// @brief Libera a memoria da lista
/// @param lista valida
void LiberaListaAmizade(ListaAmizade *lista);

/* Funcoes de impressao */

/// @brief Imprime o arquivo de similaridades
/// @param relacao valida
/// @param arquivo valido
void ImprimeSimiladiridade(Amizade *relacao, FILE *file);


#endif // !_LISTAAMIZADE_H_
