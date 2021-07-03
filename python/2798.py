n, m = map(int, input().split())

a = list(map(int, input().split()))
b = []

for i in range(0, n-2):
    for j in range(i+1, n-1):
        for k in range(j+1, n):
            result = a[i]+a[j]+a[k]
            if(result <= m):
                b.append(result)

print(max(b))
