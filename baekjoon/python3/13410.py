N,K=map(int,input().split())
M=N
for i in range(1,K+1):
	t=int(str(N*i)[::-1])
	if M < t:M = t
print(M)