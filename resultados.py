import os, sys, random

n = 100

os.system('gcc ./Btree/*.c -o Btree/btree')
os.system('gcc ./avltree/*.c -o avltree/avl')

# rodar gerar 10 vezes pra numeros aleatórios e pegar a média

# roda pior caso

out_avltree_rand = open(f'outs_piorcaso/out_avltree_rand', 'w').close()
out_btree_rand = open(f'outs_piorcaso/out_btree_rand', 'w').close()


for k in range(1):

    # out_avltree_rand = open(f'./outs_piorcaso/out_avltree_rand', 'a')
    out_btree_rand = open(f'./outs_piorcaso/out_btree_rand', 'a')

    # out_avltree_rand.write(f'{k+1}\n')
    out_btree_rand.write(f'{k+1}\n')

    # out_avltree_rand.close()
    out_btree_rand.close()

    for i in range(10):
        os.system(f'./avltree/avl < ./rand_ins{k}/in{i} > out_avl')
        os.system(f'./Btree/btree < ./rand_ins{k}/in{i} > out_b')
        print(i)
    

# out_avltree = open('outs_piorcaso/out_avltree', 'w').close()
# out_btree = open('outs_piorcaso/out_btree', 'w').close()

# for i in range(n):
#     os.system(f' ./avltree/avl < ./ins/in{i} > out_avl')
#     os.system(f'./Btree/btree < ./ins/in{i} > out_b')

#     out_avltree = open('./outs_piorcaso/out_avltree', 'a')
#     out_btree = open('./outs_piorcaso/out_btree', 'a')
#     out_avltree.close()
#     out_btree.close()

