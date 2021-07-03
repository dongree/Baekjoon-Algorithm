k = int(input())

b = [0 for i in range(k+1)]

b[1] = 1

for i in range(2, k+1):
    b[i] = b[i-1] + b[i-2]
print(b[k-1], b[k])

# an = bn-1
# bn = bn-2 + bn-1
