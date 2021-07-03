# 내 풀이 - 조합 규칙 풀이
#  n = int(input())

# result = 0
# i = 0
# while(n-i != -1 and n-i != -2):
#     mother = 1
#     son = 1
#     # combination 수 구하기
#     for a in range(n, n-i, -1):
#         mother *= a
#         son *= a-(n-i)
#     result += mother//son
#     n -= 1
#     i += 1

# print(result % 10007)

# n1 1
# n2 1+1  2c0 1c1
# n3 1+2  3c0+2c1
# n4 1+3+1  4c0+3c1+2c2
# n5 1+4+3  5c0+4c1+3c2  2 3
# n6 1+5+6+1 6c0+5c1+4c2+3c3 2 4
# n7 1+6+10+4 7c0+6c1+5c2+4c3

# nn nC0+n-1C1+n-2C2


# DP 풀이
n = int(input())
s = [0, 1, 2]

if n != 1 or n != 2:
    for i in range(3, n+1):
        s.append(s[i-1]+s[i-2])

print(s[n] % 10007)
