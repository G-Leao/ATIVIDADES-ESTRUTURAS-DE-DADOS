# Atividade Avaliativa 1 - Recursividade em C

## Integrantes
- Gustavo Leao (g-leao)
- Henrique Alves(henriquevieira09)

- Joao iuki(joaoiuki)
- Adrian(


## Exercícios Desenvolvidos

### 1. Fibonacci Recursivo
Implementação da sequência de Fibonacci usando recursividade sem otimização, demonstrando a ineficiência através da contagem de chamadas recursivas.
Caso base:
 Se n for 0 ou 1, retorna o próprio valor.
Redução do problema:
 A função chama fibonacci(n-1) e fibonacci(n-2).

 
## 2. Fibonacci com Memoização
Versão otimizada da sequência de Fibonacci utilizando memoização com alocação dinâmica de memória para armazenar resultados já calculados.


 Caso base:
 Se n for 0 ou 1, retorna o próprio valor.
 Redução:
 Resolve fibonacciMemo(n-1) e fibonacciMemo(n-2),
armazenando resultados já calculados.


## 3. Torres de Hanoi
Solução recursiva do problema das Torres de Hanoi, exibindo todos os movimentos realizados e a quantidade total de movimentos.

 Redução do problema:
   Move n-1 discos para a torre auxiliar,
 move o maior disco,
  depois move os n-1 discos restantes.

  
## Conceitos Utilizados
- Recursividade
- Caso base
- Divisão de problemas
- Memoização
- Alocação dinâmica de memória
- Backtracking lógico nas chamadas recursivas



gcc arquivo.c -o programa
./programa
