A = []
N, L, R = map(int, input().split())
A = list(map(int,input().split()))

S = 0
for i in range(N-1):
	for j in range(i+1, N):
		S += R//A[i] - L//A[i] + R//A[j] - L//A[j] - R//(A[i]*A[j]) + L//(A[i]*A[j])

print(S)