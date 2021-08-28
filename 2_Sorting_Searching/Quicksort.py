

def quicksort(A, l, r):
    if (r<=l):
        return 0
    p = [l, (l+r)//2, r]
    A1 = [A[l], A[(l+r)//2], A[r]]
    #print("\n", p)
    #print(A1)
    p = [x for _,x in sorted(zip(A1,p))]
    #print(p)
    t = A[p[1]]
    A[p[1]] = A[l]
    A[l] = t
    piv = A[l]
    #print("\n med : ", piv)
    j = l+1
    for i in range(l+1, r+1):
        if(A[i]<piv):
            tmp = A[i]
            A[i]=A[j]
            A[j]=tmp
            j = j+1
    A[l] = A[j-1]
    A[j-1] = piv
    n1 = quicksort(A, l, j-2)
    n2 = quicksort(A, j, r)
    #print(n1,n2)
    #print(A[l:r+1])
    #print(r-l+n1+n2)
    return r-l+n1+n2

f = open('./quix.txt', 'r')
Arr = []
strng = f.read()
f.close()
strt, end = 0, 0
i = 0
while(i<len(strng)):
    if(strng[i] == '\n'):
        end = i
        no = int(strng[strt:end])
        print(no)
        Arr = Arr + [no]
        strt = i+1
    i = i+1


print('Length:', len(Arr))
comp = quicksort(Arr, 0, len(Arr)-1)
print('No. of comparisons : ',comp)