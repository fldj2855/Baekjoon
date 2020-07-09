N=int(input())
S=[]
def B(S, k):
	if k-1 == N:
		print(*S,sep='')
		exit()
	for i in "123":
		S+=[i]
		if (0 if sum(S[k-2*i:k-i]==S[k-i:k] for i in range(1,k+1)) else 1):B(S,k+1)
		del S[-1]
B(S,1)