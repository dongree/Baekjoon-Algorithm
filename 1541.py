# 내 풀이
# a = input()
# a += '/'

# flag = True

# k = ''
# result = 0
# for i in range(len(a)):
#     if a[i] == '-':
#         if flag == True:
#             result += int(k)
#             k = ''
#             flag = False
#         else:
#             result -= int(k)
#             k = ''
#             flag == True
#     elif a[i] == '+' or a[i] == '/':
#         if flag == True:
#             result += int(k)
#             k = ''
#         else:
#             result -= int(k)
#             k = ''
#     else:
#         k += a[i]
# print(result)

# 다른 사람 풀이 참고
a = input().split('-')
num = []

for i in a:
    k = 0
    b = i.split('+')
    for j in b:
        k += int(j)
    num.append(k)
result = num[0]
for i in range(1, len(num)):
    result -= num[i]

print(result)
