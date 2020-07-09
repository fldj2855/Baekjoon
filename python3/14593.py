import sys
n=int(input())
scoreboard = []

for i in range(1, n+1):
	K = list(map(int,sys.stdin.readline().split())) + [i]
	K[1] *= -1
	K[2] *= -1
	scoreboard.append(K)
#print(sorted(scoreboard))
print(sorted(scoreboard)[-1][-1])