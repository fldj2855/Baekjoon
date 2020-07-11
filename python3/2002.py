N = int(input())

CAR = {}

for i in range(1,N+1):
	CAR[input()] = i

final_list = [0]*N
for i in range(N):
	final_list[i] = CAR[input()]-1

print(*final_list)
cnt = 0
final_bits = [False]*N
for i in range(N):
	if final_bits[i]:
		continue
	else:
		for j in range(i, N):
			if final_list[j] == i:
				final_bits[j] = True
				break

			if final_bits[j] == False:
				final_bits[final_list[j]] = True
				cnt+=1

	print(*final_bits)

print(cnt)