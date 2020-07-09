n=int(input())

for i in range(n):
	text = ""
	while True:
		K = input()
		print(K)
		if K == '\n':
			break
		text += K

	print(text)