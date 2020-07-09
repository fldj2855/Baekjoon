import sys
T=int(input())
for i in range(T):
	n = int(input())
	L = list(map(str,sys.stdin.readline().split()))
	text = L[0]
	for j in range(1, n):
		if ord(L[j]) <= ord(text[0]):text = L[j] + text
		else:text = text + L[j]
	print(text)