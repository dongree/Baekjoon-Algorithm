t = int(input())

for _ in range(t):
    k = int(input())
    n = int(input())
    apart = [[0 for col in range(n)] for row in range(k+1)]
    for i in range(k+1):
        for j in range(n):
            if (i == 0):
                apart[i][j] = j+1
            elif (j == 0):
                apart[i][j] = 1
            else:
                apart[i][j] = apart[i-1][j] + apart[i][j-1]

    print(apart[i][j])
