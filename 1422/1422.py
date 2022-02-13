K,N=map(int,input().split())
a=[int(input())for _ in' '*K]
print(*sorted(a+[max(a)]*(N-K),key=lambda x:str(x)*9)[::-1],sep='')