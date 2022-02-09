def MatMul(A, B, M=1000):
    retMat = [[0 for i in range(N)] for i in range(N)]

    for i in range(N):
        for j in range(N):
            for z in range(N):
                retMat[i][j] += A[i][z] * B[z][j] ;
            retMat[i][j] %= 1000;

    return retMat

def MatPow(A, exp, M=1000):
    if exp == 1:
        return MatMul(A, U)
    elif exp == 2:
        return MatMul(A, A)

    memo = MatPow(A, exp//2)
    if exp%2:
        return MatMul(
                    MatMul(memo,memo),
                    A
                )
    else:
        return MatMul(
                    memo,
                    memo
                )

N,B=map(int,input().split())

A = []
U = [[0 for i in range(N)] for i in range(N)]
for i in range(N):
    U[i][i] = 1

for i in range(N):
    A.append(list(map(int, input().split())))

A=MatPow(A, B)
for i in range(N):
    print(*A[i])