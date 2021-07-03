# 내 풀이
# a = [['' for _ in range(15)] for _ in range(5)]

# k = []
# result = ''

# for _ in range(5):
#     k.append(input())

# for i in k:
#     for j in range(len(i)):
#         a[k.index(i)][j] = i[j]

# for m in range(15):
#     for n in range(5):
#         result += a[n][m]

# print(result)


#  다른 사람 풀이
A = [list(input()) for _ in range(5)]
for j in range(15):
    for i in range(5):
        if j < len(A[i]):
            print(A[i][j], end="")
