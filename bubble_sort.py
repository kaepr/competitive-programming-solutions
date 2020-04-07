times = [66, 57, 54, 53, 64, 52, 59]
n = len(times)
print(n)
for i in range(n):
    for j in range(0, n-i-1):
        if times[j] > times[j+1]:
            times[j], times[j+1] = times[j+1], times[j]

print(times)