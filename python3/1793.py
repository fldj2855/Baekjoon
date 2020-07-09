L=[1,1]
exec("L+=[L[-2]*2+L[-1]];"*250)
while 1:
	try:print(L[int(input())])
	except:break