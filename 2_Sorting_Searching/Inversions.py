def count_split_inversions(A1, A2):
    n1 = len(A1)
    n2 = len(A2)
    A = A1 + A2
    A1 = A1 + [max(A)+1]
    A2 = A2 + [max(A)+1]
    n = n1+n2
    i,j, inv = 0,0,0
    for k in range(n):
        if(A1[i]<=A2[j]):
            A[k] = A1[i]
            i+=1
        else:
            A[k] = A2[j]
            j+=1
            inv += n1-i
    return inv, A 


def count_inverions(A):
    if len(A)<2:
        return 0, A
    A1 = A[:len(A)//2]
    A2 = A[len(A)//2:]
    L, A1 = count_inverions(A1)
    R, A2 = count_inverions(A2)
    S, A = count_split_inversions(A1, A2)
    return L+S+R, A

f = open('./inv.txt', 'r')
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
inv, Srt = count_inverions(Arr)
print('No. of inversions : ',inv)
print(Srt[99950:])