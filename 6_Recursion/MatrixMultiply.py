import numpy as np

def simpleMult(A,B):
    rA=len(A)
    cA=len(A[0])
    rB=len(B)
    cB=len(B[0])
    C=[]
    if(cA==rB):
        for i in range(0,rA):
            C=C+[[]]
            for j in range(0,cB):
                C[i]=C[i]+[0]
                for k in range(0,cA):
                    C[i][j]=C[i][j]+A[i][k]*B[k][j]
        return C
    else:
        return None

def divNconMult(A,B):
    rA=len(A)
    cA=len(A[0])
    rB=len(B)
    cB=len(B[0])
    print(rA,cA,rB,cB)
    C=[]
    if(cA==rB):
        if(cA==1):
            C=A*B
        else:
            A11=A[0:(rA//2)][0:(cA//2)]
            A12=A[0:rA//2][(cA//2):cA]
            A21=A[(rA//2):rA][0:cA//2]
            A22=A[(rA//2):rA][(cA//2):cA]
            B11=B[0:rB//2][0:cB//2]
            B12=B[0:rB//2][(cB//2):cB]
            B21=B[(rB//2):rB][0:cB//2]
            B22=B[(rB//2):rB][(cB//2):cB]
            C11=divNconMult(A11,B11)+divNconMult(A12,B21)
            C12=divNconMult(A11,B12)+divNconMult(A12,B22)
            C21=divNconMult(A21,B11)+divNconMult(A22,B21)
            C22=divNconMult(A21,B12)+divNconMult(A22,B22)
            C=C+[[C11,C12],[C21,C22]]
            return C
    else:
        return None




print(divNconMult([[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]],[[1,5,1,9],[2,9,3,6],[3,1,2,5],[1,2,3,4]]))
