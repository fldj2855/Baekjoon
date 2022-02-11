K,N=map(int,input().split())
a=[]
exec("a+=[input()];"*K)
a+=[max(a,key=lambda x:int(x))]*(N-K)
print(''.join(sorted(a,key=lambda x:x*9)[::-1]))