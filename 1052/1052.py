import sys

bottle = []

N, K = map(int, sys.stdin.readline().split())

if N < K:
    print("-1")
    exit(0)

while N:
    bottle.append(N%2)
    N //= 2

p = [2**i for i in range(len(bottle))]
print(bottle)
print(p)
