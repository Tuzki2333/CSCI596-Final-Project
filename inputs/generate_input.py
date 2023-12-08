import sys, random

def generate_input(n=1000, W=100, seed=1):
    random.seed(seed)
    items = []
    for i in range(n):
        v = random.randint(1, 100)/100
        w = random.randint(1, 100)/100
        items.append((v,w))
    f = open("knapsackInstance-n-"+str(n)+"-W-"+str(W)+"-seed-"+str(seed)+".txt", "w")
    f.write(str(n)+" "+str(W)+"\n")
    for v,w in items:
        f.write(str(v) + " " + str(w) + "\n")
    f.close()


if __name__ == '__main__':
    for i in range(5):
        for seed in range(1, 6):
            W = 10 ** i
            n = W * 10
            generate_input(n, W, seed)