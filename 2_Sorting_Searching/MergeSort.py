def merge(A,p,q,r):
    """ This function merges 2 sorted subarrays A[p .. q] and A[q+1 .. r] into a single sorted array A[p .. r]"""
    A1 = A[p:q]
    A2 = A[q:r]
    A1 = A1 + [max(A)+1]
    A2 = A2 + [max(A)+1]
    i, j = 0,0
    for k in range(p,r):
        if(A1[i]<=A2[j]):
            A[k] = A1[i]
            i+=1
        else:
            A[k] = A2[j]
            j+=1
    return A

def mrgSort(A,p,r):
    if(p<(r-1)):
        q = (p+r)//2
        A = mrgSort(A,p,q)
        A = mrgSort(A,q,r)
        A = merge(A,p,q,r)
    return A

A = [6, 3, 5, 9, 1, 4, 8, 19, 13, 2]
mrgSort(A, 0, len(A))
print(A)