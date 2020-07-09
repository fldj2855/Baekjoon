n=input()+"-0"
k=n.find('-')
n=[n[:k].split('+'), n[k+1:].replace('-','+').split('+')]
t=[[int(j) for j in n[i]] for i in range(2)]
print(sum(t[0])-sum(t[1]))