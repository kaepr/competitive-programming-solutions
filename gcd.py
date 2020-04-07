def gcd(a, b):
    if a == 0:
        return b
    return gcd(b%a, a)

a = 10234324324
b = 151312321
print(gcd(a,b))