def crossmid(A,beg,mid,end):
    maxl=A[mid]
    lindx = mid
    maxr=A[mid+1]
    hindx = mid+1
    sum=0
    for i in range(mid,beg,-1):
        sum+=A[i]
        if maxl<sum:
            maxl=sum
            lindx=i
    sum=0
    for i in range(mid+1,end):
        sum+=A[i]
        if maxr<sum:
            maxr=sum
            hindx=i
    max=maxl+maxr
    return max,lindx,hindx

def maxsubarray(A,beg,end):
    if beg==end:
        return A[beg],beg,end
    else:
        mid=(beg+end)//2
        maxl,lli,lhi = maxsubarray(A,beg,mid)
        maxr,rli,rhi = maxsubarray(A,mid+1,end)
        maxc,cli,chi = crossmid(A,beg,mid,end)
        if(maxl>maxr and maxl>maxc):
            return maxl,lli,lhi
        elif(maxr>maxl and maxr>maxc):
            return maxr,rli,rhi
        else:
            return maxc,cli,chi

A = [13,-3,-25,20,-3,-16,-23,18,20,-7,12,5,-22,15,-4,7]

print(maxsubarray(A,0,len(A)-1))