import os, sys, random

num_pastas = 10
n = 100

# cria pastas de ins para números ordenados
for i in range(n):
    f = open(f'./ins/in{i}', 'w')

    f.write(f'{1}\n')
    f.write(f'{i+1}\n')
    for j in range(i+1):
        f.write(f'{j}\n')

    f.close()

# cria pastas de ins para números randomicos
for k in range(num_pastas):
    for i in range(n):
        f_rand = open(f'./rand_ins{k}/in{i}', 'w')

        f_rand.write(f'{2}\n')
        f_rand.write(f'{i+1}\n')
        for j in range(i+1):
            f_rand.write(f'{random.randint(1, 1000)}\n')

        f_rand.close()