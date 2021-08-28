def insSort(A, rev=False):
    """ This function uses Insertion Sort technique to sort an input array A in ascending order if rev=False(default) and in descending order if rev=True """
    for i in range(1,len(A)):
        key = A[i]
        # Insert A[i] in the sorted sequence A[1 .. i-1]
        j = i-1
        while(j>=0 and (rev == bool(A[j]<key))):
            A[j+1] = A[j]
            j-=1
        A[j+1] = key
    return A

