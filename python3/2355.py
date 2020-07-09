a,b=sorted(list(map(int,input().split())))

def sum(n):
	return n*(n+1)//2
	
print(sum(b)-sum(a-1))