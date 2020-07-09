import sys
a = input()

n = int(input())

command = list(map(str,sys.stdin.readline().split()))


for i in command:
	if i == "char":
		bi = a[:2]
		print(int(bi,16), end=" ")
		a = a[2:]
	elif i == "int":
		bi = a[:8]
		print(int(bi,16), end=" ")
		a = a[8:]
	elif i == "long_long":
		bi = a[:16]
		print(int(bi, 16), end=" ")
		a = a[16:]
