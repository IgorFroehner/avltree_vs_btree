import os, sys

os.system('gcc ./Btree/*.c -o btree')
os.system('gcc ./avltree/*.c -o avl')

# rodar gerar 10 vezes pra numeros aleatórios e pegar a média

# roda pior caso

out_avltree = open('outs_piorcaso/out_avltree', 'w').close()
out_btree = open('outs_piorcaso/out_btree', 'w').close()


for i in range(4):
    # f = open(f'./ins/in{i}', 'w')

    # f.write(f'{i+1}\n')
    # for j in range(i+1):
    #     f.write(f'{j}\n')

    os.system(f'./avl < ./ins/in{i} > out_avl')
    os.system(f'./btree < ./ins/in{i} > out_b')

    out_avltree = open('outs_piorcaso/out_avltree', 'a')
    out_btree = open('outs_piorcaso/out_btree', 'a')

    # print(f'saida_avl')
    # print(saida_b)

    out_avltree.close()
    out_btree.close()

    # f.close()

