def karatsuba(a, b):
    x = max(a, b)
    n=0 
    while(x!=0):
        x = x//10
        n=n+1
    if (a<=10 or b<=10):
        return a*b
    n = n//2
    a1 = a//(10**(n))
    a2 = a%(10**(n))
    b1 = b//(10**(n))
    b2 = b%(10**(n))
    a1b1 = karatsuba(a1, b1)
    a2b2 = karatsuba(a2, b2)
    mul = karatsuba((a1+a2), (b1+b2))
    ans = (10**(2*n))*a1b1 + (10**n)*(mul-a1b1-a2b2) + a2b2
    return ans

A = 3141592653589793238462643383279502884197169399375105820974944592
B = 2718281828459045235360287471352662497757247093699959574966967627
print(karatsuba(A, B))