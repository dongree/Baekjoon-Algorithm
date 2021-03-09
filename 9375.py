#  다른 사람 풀이 참고
# (type1 개수+1)*(tpye2 개수+1)* ... -1

import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    clothesType = []
    for _ in range(n):
        _, b = input().split()
        clothesType.append(b)
    result = 1
    for i in set(clothesType):
        result *= (clothesType.count(i)+1)
    print(result-1)


# 다른 사람풀이, Counter함수 기억!!
# from collections import Counter
# t = int(input())
# for i in range(t):
#     n = int(input())
#     s = []
#     for j in range(n):
#         a, b = input().split()
#         s.append(b)
#     num = 1
#     result = Counter(s)
#     print(result)
#     for key in result:
#         num *= result[key] + 1
#     print(num - 1)
