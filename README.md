# Análise de Complexidade Entre árvore AVL e árvore B

O objetivo deste trabalho consiste em analisar a complexidade algorítmica das operações de adição de nós e balanceamento em árvores AVL e Árvores B. A análise deve ser realizada considerando a geração de um conjunto de dados (chaves) com tamanho variando entre 1 e 100. As chaves devem ser geradas prevendo o pior caso (chaves ordenadas crescente ou decrescente) e caso médio (chaves aleatórias). Para geração das chaves aleatórias, sugere-se o uso da função rand e srand em C considerando um tamanho de amostra de 10 conjuntos para validade estatística.

O resultado final do experimento deve ser exibido em dois gráfico de linha (um para o pior caso e outro para o caso médio), onde o eixo X representa o tamanho dos conjuntos de dados (1 a 100) e o eixo Y representa o esforço computacional das operações (adição de chaves e balanceamento). O gráfico deve apresentar 2 linhas, as quais representam as respectivas operações para cada estrutura de dados avaliada.

# Getting Started

Para conseguir rodar este projeto, você precisa ter:
- suporte para compiladores C (como GCC). 
- versão 3 do Python.


Para visualizar o resultado gerado por este trabalho, você precisa executar esses comandos em seu terminal, em sequência:
    
    $~ python3 gerador.py

    $~ python3 resultados.py

Esses comandos gerarão:
- pastas rand_ins{i} | 0 <= i < 10 e para cada pasta, serão geradas k entradas in{k} | 0 <= k < 100, contendo 10 pastas com 100 entradas
- pasta ins, dentro da pasta, serão geradas k entradas in{k} | 0 <= k < 100

As entradas geradas serão usadas para comparar a AVL Tree e a B Tree.

Com as entradas geradas, também haverá 4 pastas de saída em outs_piorcaso:
- out_avltree: Quantidade de iterações para geração da árvore AVL a partir das entradas ordenadas;
- out_avltree_rand: Quantidade de iterações para geração da árvore AVL a partir das entradas randômicas;
- out_btree: Quantidade de iterações para geração da árvore B a partir das entradas ordenadas;
- out_btree_rand: Quantidade de iterações para geração da árvore B a partir das entradas randômicas;
