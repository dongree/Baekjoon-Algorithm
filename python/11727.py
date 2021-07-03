# 내 풀이 - combination
# n = int(input())

# result = 0
# i = 0
# while(n-i != -1 and n-i != -2):
#     mother = 1
#     son = 1
#     # combination 수 구하기
#     for a in range(n, n-i, -1):
#         mother *= a
#         son *= a-(n-i)
#     result += (mother//son)*(2**i)
#     n -= 1
#     i += 1

# print(result % 10007)

# n1 1
# n2 1+1*2  2c0 1c1*2
# n3 1+2*2  3c0+2c1*2
# n4 1+3*2+1*4  4c0+3c1*2+2c2*4
# n5 1+4*2+3*4  5c0+4c1*2+3c2*4  2 3
# n6 1+5*2+6*4+1*8 6c0+5c1*2+4c2*4+3c3*8 2 4
# n7 1+6*2+10*4+4*8 7c0+6c1*2+5c2*4+4c3*8

# DP 풀이
n = int(input())
s = [0, 1, 3]

if n != 1 or n != 2:
    for i in range(3, n+1):
        s.append(s[i-1]+s[i-2]*2)

print(s[n] % 10007)
