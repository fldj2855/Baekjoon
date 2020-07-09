N, T = map(int, input().split())

T %= N*4-2	
if T == 0:
	print(2)
elif T > N*2:
	print(N*2 - T%(N*2))
else:
	print(T)