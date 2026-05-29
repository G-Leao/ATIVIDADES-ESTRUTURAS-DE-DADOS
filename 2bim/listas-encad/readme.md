
# Estruturas de Dados em C — Listas Encadeadas

## 📚 Sobre o Projeto

Este projeto foi desenvolvido para a atividade avaliativa da disciplina de Estruturas de Dados.

O objetivo é implementar operações utilizando:

* Lista simplesmente encadeada
* Lista circular duplamente encadeada

O projeto foi desenvolvido na linguagem C utilizando alocação dinâmica de memória com `malloc` e `free`.

---

# ✅ Funcionalidades

## Parte 1 — Inserção em posição específica

Implementação da função:

```c
void inserirPosicao(No **head, int valor, int posicao);
```

Permite inserir elementos:

* no início
* no meio
* no final
* em lista vazia

---

## Parte 2 — Busca por valor

Implementação da função:

```c
int buscarValor(No *head, int valor);
```

Retorna:

* posição da primeira ocorrência
* `-1` caso o valor não seja encontrado

---

## Parte 3 — Inverter lista

Implementação da função:

```c
void inverterLista(No **head);
```

Realiza a inversão da lista utilizando apenas ponteiros.

---

## Parte 4 — Dividir lista

Implementação da função:

```c
void dividirLista(No *head, No **lista1, No **lista2);
```

Utiliza a técnica de ponteiro rápido/lento para dividir a lista em duas partes.

---

## Parte 5 — Playlist Circular Duplamente Encadeada

Implementação de uma playlist utilizando lista circular duplamente encadeada.

### Funções implementadas:

* adicionar música
* próxima música
* música anterior
* exibir playlist
* total de músicas

A playlist permite navegação contínua entre as músicas.

---

# ▶️ Compilação

Compile o programa com:

```bash
gcc main.c -o programa
```

Execute com:

```bash
./programa
```

---

# 🧠 Conceitos Utilizados

* Ponteiros
* Structs
* Alocação dinâmica
* Listas encadeadas
* Lista duplamente encadeada
* Lista circular
* Manipulação de memória

---

# 👨‍💻 Integrantes

Gustavo Leão 
joão Iuki
Henrique Alves
Adrian Juliano

---

# 📌 Observações

* O projeto não utiliza vetores auxiliares.
* Toda memória alocada é liberada corretamente com `free`.
* Código desenvolvido apenas com:

```c
stdio.h
stdlib.h
```
