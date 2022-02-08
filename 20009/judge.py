from subprocess import Popen, PIPE

# judge myself special judge..
# compare sorted answer

for i in range(1, 10):
    IN = ""
    AC = ""
    with open("./data/%d.in"%(i), "rb") as f:
        IN = f.read()

    with open("./data/%d.out"%(i), "r") as f:
        AC = f.read().rstrip().split('\n')

    p = Popen(["./20009"], shell=True, stdout=PIPE, stdin=PIPE)
    myout = p.communicate(input=IN)[0].decode()
    
    myout = myout.rstrip().split("\n")

    try:
        assert(sorted(myout) == sorted(AC))
    except AssertionError:
        print("Error case : %d"%(i))
    
    