a=[i for i in range(1,31)]
exec('a.remove(int(input()));'*28)
print(*a,sep='\n')