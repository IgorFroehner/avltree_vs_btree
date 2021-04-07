import numpy as np
import matplotlib.pyplot as plt

plt.rcParams.update({'font.size': 24})  # font size

avltree = []
media_avl = [0] * 100
btree = []
media_b = [0] * 100

def make_plot(title, avl, b, path):
    path = "plot/"

    plt.figure(figsize=(20.3, 13))

    plt.title(title)
    plt.ylabel('Complexidade')
    plt.xlabel('Tamanho da entrada')

    plt.xticks(np.arange(0, 101, 10))
    plt.yticks(np.arange(min(b), max(b), 100))
    plt.plot(list(range(1,101)), avl, label='avltree')
    plt.plot(list(range(1,101)), b, label='btree')

    plt.legend(loc = 'upper left')

    plt.savefig(path + title + ".png")

def media(array):
    return 0

if __name__ == "__main__":

    # avltree
    avl_out = open("./outs_piorcaso/out_avltree", "r")
    avltree = avl_out.read().split('\n')
    avltree.pop()
    avltree = list(map(int, avltree))

    # btreee
    avl_out = open("./outs_piorcaso/out_btree", "r")
    btree = avl_out.read().split('\n')
    btree.pop()
    btree = list(map(int, btree))
    # print(btree)

    # avltree rand
    avl_out_random = open("./outs_piorcaso/out_avltree_rand", "r")
    avltree_random = avl_out_random.read().replace('\n', ';').split(';')
    avltree_random.pop()

    for i in range(1000):
        media_avl[i%100]+=int(avltree_random[i])

    for i in range(100):
        media_avl[i]/=10
        
    # print(avltree_random)
    # print(media_avl)

    # btree rand
    b_out_random = open("./outs_piorcaso/out_btree_rand", "r")
    btree_random = b_out_random.read().replace('\n', ';').split(';')
    btree_random.pop()

    for i in range(1000):
        media_b[i%100]+=int(btree_random[i])

    for i in range(100):
        media_b[i]/=10
        
    # print(btree_random)
    # print(media_b)


    make_plot('Números em sequência', avltree, btree, 'seq')
    make_plot('Números Randômicos', media_avl, media_b, 'random')
    

    
