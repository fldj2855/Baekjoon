k = input()

if k.count('0') == 0 or eval("+".join(k))%3 != 0:
	print(-1)
else:
	for i in range(9,-1,-1):
		print(str(i)*k.count(str(i)), end='')