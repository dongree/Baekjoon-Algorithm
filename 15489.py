r, c, w = map(int, input().split())

pa = [[0 for j in range(i+1)] for i in range(0, r+w-1)]

for i in range(0, r+w-1):
    for j in range(i+1):
        if j == 0 or j == i:
            pa[i][j] = 1
        else:
            pa[i][j] = pa[i-1][j-1] + pa[i-1][j]

result = 0

for i in range(r-1, r+w-1):
    for j in range(c-1, i-r+c+1):
        result += pa[i][j]

print(result)
