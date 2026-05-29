#include <stdio.h>
#include <stdlib.h>

/* =========================================================
   PARTE 1 A 4 - LISTA ENCADEADA SIMPLES
========================================================= */

typedef struct NoSimples {
    int valor;
    struct NoSimples *prox;
} NoSimples;

/* Criar nó */
NoSimples* criarNo(int valor) {
    NoSimples *novo = (NoSimples*) malloc(sizeof(NoSimples));

    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }

    novo->valor = valor;
    novo->prox = NULL;

    return novo;
}

/* Inserir no final */
void inserirFinal(NoSimples **head, int valor) {
    NoSimples *novo = criarNo(valor);

    if (*head == NULL) {
        *head = novo;
        return;
    }

    NoSimples *temp = *head;

    while (temp->prox != NULL) {
        temp = temp->prox;
    }

    temp->prox = novo;
}

/* Exibir lista */
void exibirListaSimples(NoSimples *head) {
    while (head != NULL) {
        printf("%d -> ", head->valor);
        head = head->prox;
    }

    printf("NULL\n");
}

/* =========================================================
   PARTE 1 - INSERIR EM POSICAO ESPECIFICA
========================================================= */

void inserirPosicao(NoSimples **head, int valor, int posicao) {

    if (posicao < 0) {
        printf("Posicao invalida!\n");
        return;
    }

    NoSimples *novo = criarNo(valor);

    /* Inserção no início */
    if (posicao == 0) {
        novo->prox = *head;
        *head = novo;
        return;
    }

    NoSimples *temp = *head;
    int i = 0;

    while (temp != NULL && i < posicao - 1) {
        temp = temp->prox;
        i++;
    }

    if (temp == NULL) {
        printf("Posicao invalida!\n");
        free(novo);
        return;
    }

    novo->prox = temp->prox;
    temp->prox = novo;
}

/* =========================================================
   PARTE 2 - BUSCAR VALOR
========================================================= */

int buscarValor(NoSimples *head, int valor) {

    int posicao = 0;

    while (head != NULL) {

        if (head->valor == valor) {
            return posicao;
        }

        head = head->prox;
        posicao++;
    }

    return -1;
}

/* =========================================================
   PARTE 3 - INVERTER LISTA
========================================================= */

void inverterLista(NoSimples **head) {

    NoSimples *anterior = NULL;
    NoSimples *atual = *head;
    NoSimples *proximo = NULL;

    while (atual != NULL) {

        proximo = atual->prox;

        atual->prox = anterior;

        anterior = atual;
        atual = proximo;
    }

    *head = anterior;
}

/* =========================================================
   PARTE 4 - DIVIDIR LISTA
========================================================= */

void dividirLista(NoSimples *head, NoSimples **lista1, NoSimples **lista2) {

    if (head == NULL) {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }

    NoSimples *lento = head;
    NoSimples *rapido = head->prox;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    *lista1 = head;
    *lista2 = lento->prox;

    lento->prox = NULL;
}

/* Liberar lista simples */
void liberarListaSimples(NoSimples *head) {

    NoSimples *temp;

    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);
    }
}

/* =========================================================
   PARTE 5 - PLAYLIST CIRCULAR DUPLAMENTE ENCADEADA
========================================================= */

typedef struct No {
    char musica[100];
    struct No *prox;
    struct No *ant;
} No;

/* Copiar string sem usar string.h */
void copiarTexto(char destino[], char origem[]) {

    int i = 0;

    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';
}

/* Criar nó da playlist */
No* criarMusica(char nome[]) {

    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }

    copiarTexto(novo->musica, nome);

    novo->prox = novo;
    novo->ant = novo;

    return novo;
}

/* Adicionar música */
void adicionarMusica(No **head, char nome[]) {

    No *novo = criarMusica(nome);

    /* Lista vazia */
    if (*head == NULL) {
        *head = novo;
        return;
    }

    No *ultimo = (*head)->ant;

    ultimo->prox = novo;
    novo->ant = ultimo;

    novo->prox = *head;
    (*head)->ant = novo;
}

/* Próxima música */
void proximaMusica(No **atual) {

    if (*atual != NULL) {
        *atual = (*atual)->prox;
    }
}

/* Música anterior */
void musicaAnterior(No **atual) {

    if (*atual != NULL) {
        *atual = (*atual)->ant;
    }
}

/* Exibir playlist */
void exibirPlaylist(No *head) {

    if (head == NULL) {
        printf("Playlist vazia!\n");
        return;
    }

    No *temp = head;

    do {
        printf("[%s] <-> ", temp->musica);
        temp = temp->prox;
    } while (temp != head);

    printf("(volta ao inicio)\n");
}

/* Total de músicas */
int totalMusicas(No *head) {

    if (head == NULL) {
        return 0;
    }

    int total = 0;
    No *temp = head;

    do {
        total++;
        temp = temp->prox;
    } while (temp != head);

    return total;
}

/* Liberar playlist */
void liberarPlaylist(No *head) {

    if (head == NULL) {
        return;
    }

    No *temp = head->prox;

    while (temp != head) {
        No *aux = temp;
        temp = temp->prox;
        free(aux);
    }

    free(head);
}

/* =========================================================
   MAIN
========================================================= */

int main() {

    printf("===== LISTA ENCADEADA =====\n");

    NoSimples *lista = NULL;

    inserirFinal(&lista, 10);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);

    exibirListaSimples(lista);

    printf("\nInserindo 99 na posicao 1:\n");
    inserirPosicao(&lista, 99, 1);

    exibirListaSimples(lista);

    printf("\nBuscando valor 20:\n");
    printf("Posicao: %d\n", buscarValor(lista, 20));

    printf("\nInvertendo lista:\n");
    inverterLista(&lista);

    exibirListaSimples(lista);

    printf("\nDividindo lista:\n");

    NoSimples *lista1 = NULL;
    NoSimples *lista2 = NULL;

    dividirLista(lista, &lista1, &lista2);

    printf("Lista 1: ");
    exibirListaSimples(lista1);

    printf("Lista 2: ");
    exibirListaSimples(lista2);

    liberarListaSimples(lista1);
    liberarListaSimples(lista2);

    /* ===================================================== */

    printf("\n===== PLAYLIST =====\n");

    No *playlist = NULL;

    adicionarMusica(&playlist, "Rock");
    adicionarMusica(&playlist, "Jazz");
    adicionarMusica(&playlist, "Pop");

    exibirPlaylist(playlist);

    printf("\nTotal de musicas: %d\n", totalMusicas(playlist));

    No *atual = playlist;

    printf("\nMusica atual: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Proxima: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Proxima: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Proxima: %s\n", atual->musica);

    musicaAnterior(&atual);
    printf("Anterior: %s\n", atual->musica);

    liberarPlaylist(playlist);

    return 0;
}
