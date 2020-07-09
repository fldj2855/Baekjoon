a=[0]*10001
k=int(input())

for i in range(k):
	a[int(input())]+=1;

M=S=0;
for i in range(10000, 0, -1):
	S += a[i]
	M = max(M, max(S*i, a[i]*i))
	
print(M)