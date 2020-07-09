T=int(input())
for i in range(T):
	leng = int(input())
	A = input()
	B = input()

	cnt = 0
	Wcnt = Bcnt = 0
	for j in range(leng):
		if A[j] != B[j]:
			if A[j] == 'W':Wcnt+=1
			else:Bcnt+=1

	while Wcnt and Bcnt:
		cnt+=1
		Wcnt-=1
		Bcnt-=1

	cnt += Wcnt + Bcnt
	print(cnt)

