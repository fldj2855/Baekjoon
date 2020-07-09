N,T,C,P=map(int,input().split())
M=0
for i in range(T+1,N+1,T):
	M+=C*P
print(M)