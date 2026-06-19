Mano, essa atividade praticamente pede um mini-artigo. Vou te entregar um conteúdo que você pode colocar diretamente no `trabalho-arvores.md`.

# Estruturas Avançadas de Árvores

## Parte 1 – Tipos de Árvores

# AVL

## Conceito

A Árvore AVL é uma árvore binária de busca balanceada criada por Adelson-Velsky e Landis. Seu principal objetivo é manter a árvore balanceada após inserções e remoções.

## Características

* Cada nó possui fator de balanceamento.
* A diferença de altura entre as subárvores esquerda e direita não pode ser maior que 1.
* Utiliza rotações para corrigir desequilíbrios.

## Vantagens

* Busca muito eficiente.
* Altura da árvore permanece próxima do ideal.
* Complexidade de busca garantida em O(log n).

## Desvantagens

* Inserções e remoções são mais complexas.
* Pode exigir várias rotações para manter o balanceamento.

## Exemplo Ilustrado

Antes:


      30
     /
    20
   /
 10


Após rotação à direita:


      20
     /  \
   10    30


# Árvore Rubro-Negra

## Conceito

É uma árvore binária de busca balanceada que utiliza cores (vermelho e preto) para controlar o balanceamento.

## Regras de Coloração

1. Todo nó é vermelho ou preto.
2. A raiz sempre é preta.
3. Nós vermelhos não podem ter filhos vermelhos.
4. Todo caminho da raiz até uma folha possui o mesmo número de nós pretos.
5. Folhas nulas são consideradas pretas.

## Vantagens

* Menos rotações que AVL.
* Boa performance para inserções e remoções.
* Utilizada em diversas bibliotecas e sistemas operacionais.

## Desvantagens

* Implementação mais complexa.
* Busca ligeiramente menos eficiente que AVL em alguns casos.

## Exemplo Ilustrado


         20(P)
        /     \
    10(V)    30(V)


P = Preto

V = Vermelho



# Árvore N-ária

## Conceito

Uma árvore N-ária é uma estrutura em que cada nó pode possuir vários filhos, diferente das árvores binárias que possuem no máximo dois.

## Diferenças em Relação às Árvores Binárias

| Binária                           | N-ária                    |
| --------------------------------- | ------------------------- |
| Até 2 filhos                      | N filhos                  |
| Estrutura mais simples            | Estrutura mais flexível   |
| Mais comum em algoritmos de busca | Mais comum em hierarquias |

## Vantagens

* Representa melhor estruturas hierárquicas.
* Menor profundidade para grandes conjuntos de dados.
* Mais natural para modelar sistemas reais.

## Desvantagens

* Implementação mais complexa.
* Consome mais memória.

## Exemplo Ilustrado


           A
       /   |   \
      B    C    D
    / | \       |
   E  F  G      H


## Aplicações Práticas

* Sistema de arquivos.
* Menus de aplicativos.
* Estrutura XML e HTML.
* Organogramas empresariais.



# Parte 2 – Operações em Árvores

# Rotação Simples à Direita

## Objetivo

Corrigir desequilíbrios causados por excesso de nós na subárvore esquerda.

## Quando é Utilizada

Caso Esquerda-Esquerda (LL).

## Exemplo

Antes:


      30
     /
    20
   /
 10


Depois:


      20
     /  \
   10    30


# Rotação Simples à Esquerda

## Objetivo

Corrigir desequilíbrios causados por excesso de nós na subárvore direita.

## Quando é Utilizada

Caso Direita-Direita (RR).

## Exemplo

Antes:


 10
   \
   20
     \
      30


Depois:


      20
     /  \
   10    30



# Rotação Dupla Esquerda-Direita (LR)

## Quando ocorre

Quando um nó é inserido à direita da subárvore esquerda.

## Exemplo

Antes:


      30
     /
    10
      \
      20


Depois:


      20
     /  \
   10    30


Primeiro ocorre uma rotação à esquerda em 10 e depois uma rotação à direita em 30.


# Rotação Dupla Direita-Esquerda (RL)

## Quando ocorre

Quando um nó é inserido à esquerda da subárvore direita.

## Exemplo

Antes:

    10
      \
      30
     /
    20


Depois:


      20
     /  \
   10    30


Primeiro ocorre uma rotação à direita em 30 e depois uma rotação à esquerda em 10.



# Inversão (Espelhamento)

## Conceito

Operação que troca todas as subárvores esquerdas pelas direitas.

## Aplicação

* Processamento de imagens.
* Estudos de estruturas de dados.
* Algoritmos de simetria.

## Exemplo

Antes:


      10
     /  \
    5   20


Depois:


      10
     /  \
   20    5



# Parte 3 – Aplicação Prática

## Sistema de Arquivos

Uma árvore N-ária é a estrutura mais adequada para representar sistemas de arquivos.

### Justificativa

Em um sistema operacional, uma pasta pode conter várias subpastas e arquivos.

Exemplo:


Documentos
├── Faculdade
├── Trabalho
├── Fotos
├── Vídeos
└── Projetos


Utilizando uma árvore N-ária:

* Cada pasta é um nó.
* Arquivos e subpastas são filhos.
* Permite número variável de elementos.
* Facilita navegação e organização.

### Desempenho

* Estrutura hierárquica natural.
* Fácil inserção de novos arquivos.
* Boa organização dos dados.



# Parte 4 – Comparação entre Estruturas

| Estrutura   | Nº Máximo de Filhos | Balanceamento                       | Complexidade de Busca                 | Complexidade de Inserção              | Vantagem Principal                  | Desvantagem Principal            | Exemplo de Aplicação                         |
| ----------- | ------------------- | ----------------------------------- | ------------------------------------- | ------------------------------------- | ----------------------------------- | -------------------------------- | -------------------------------------------- |
| BST         | 2                   | Não possui balanceamento automático | O(log n) melhor caso / O(n) pior caso | O(log n) melhor caso / O(n) pior caso | Simples de implementar              | Pode ficar desbalanceada         | Árvores de busca básicas                     |
| AVL         | 2                   | Sim, através de rotações            | O(log n)                              | O(log n)                              | Busca extremamente eficiente        | Inserção e remoção mais custosas | Sistemas com muitas consultas                |
| Rubro-Negra | 2                   | Sim, usando cores e rotações        | O(log n)                              | O(log n)                              | Menos rotações que AVL              | Implementação complexa           | Bibliotecas internas e sistemas operacionais |
| N-ária      | N                   | Pode variar conforme implementação  | O(log n) em estruturas balanceadas    | O(log n) ou dependente da estrutura   | Representa hierarquias naturalmente | Maior complexidade estrutural    | Sistema de arquivos e XML                    |

# Conclusão

As árvores AVL, Rubro-Negras e N-árias surgiram para resolver limitações das árvores binárias tradicionais. Enquanto AVL prioriza buscas rápidas através de um balanceamento rigoroso, Rubro-Negra busca equilíbrio entre desempenho e custo de manutenção. Já as árvores N-árias são ideais para representar estruturas hierárquicas com múltiplos elementos filhos, sendo amplamente utilizadas em sistemas de arquivos, documentos XML e menus de aplicações.
