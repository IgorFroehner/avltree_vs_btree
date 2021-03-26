import os

os.system('gcc ./Btree/*.c -o btree')
os.system('gcc ./avltree/*.c -o avl')

for i in range(100):
    # f = open(f'./ins/in{i}', 'w')

    # f.write(f'{i+1}\n')
    # for j in range(i+1):
    #     f.write(f'{j}\n')
    
    os.system(f'./avl < ./ins/in{i}')
    os.system(f'./btree < ./ins/in{i}')

    # f.close()

