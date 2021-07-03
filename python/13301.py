n = int(input())

cir = [0 for _ in range(81)]
cir[1] = 4
cir[2] = 6

for i in range(3, n+1):
    cir[i] = cir[i-1] + cir[i-2]

print(cir[n])

# An = An-1 + An-2
