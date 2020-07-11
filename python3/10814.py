import sys

L={}
for i in range(int(input())):
	a1, a2 = map(str, sys.stdin.readline().split())
	a1 = int(a1)
	if not a1 in L.keys():
		L[a1] = [a2]
	else:
		L[a1].append(a2)

L = sorted(L.items())

for i in L:
	for j in range(len(i[1])):
		print(i[0], i[1][j])