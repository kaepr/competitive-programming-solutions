a = [1,2,3,4,5]

length = len(a)
print(length)
for i in a:
    print(i)
    (a[length - 1],a[i]) = (a[i],a[length - 1])
    length = length - 1
    print(a)

ans = ""

for i in a:
    ans = str(a[i]) + " "

print(ans)