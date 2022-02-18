input()
s=[9**9,0]
a=[]
i=1
for j in input().split():
 while s[-2]<int(j):s=s[:-2]
 a+=[s[-1]];s+=[int(j),i];i+=1
print(*a)