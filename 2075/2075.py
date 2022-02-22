import heapq
import sys

N = int(sys.stdin.readline())

h=list(map(int, sys.stdin.readline().split()))
heapq.heapify(h)

for i in range(N-1):
    l = list(map(int,sys.stdin.readline().split()))
    for j in l:
        heapq.heappush(h, j)
        if len(h) > N:
            heapq.heappop(h);
        
print(heapq.heappop(h))