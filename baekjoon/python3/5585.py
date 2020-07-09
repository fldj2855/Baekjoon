a=1000-int(input())
cnt=0
for i in [500,100,50,10,5,1]:
	while(a>=i):
		cnt+=1
		a-=i
print(cnt)