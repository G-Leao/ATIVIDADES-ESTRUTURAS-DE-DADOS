#include <stdio.h>
#include <stdlib.h>



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
