N=input().split(':')

if '' in N:
    t = N.index('')
    N[t] = '0000'

while '' in N: N.remove('')
while len(N) != 8: N.insert(t, '0000')

print(':'.join(i.rjust(4, '0')for i in N))