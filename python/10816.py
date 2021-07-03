import sys
from collections import Counter

input = sys.stdin.readline

n = int(input())
nList = list(map(int, input().split()))

m = int(input())
mList = list(map(int, input().split()))

# Counter 클래스를 이용해서 푼 방법
counterN = Counter(nList)

for i in mList:
    print(counterN[i], end=" ")

# dictionary 자료형을 이용해서 푼 방법
# dictionary자료형이 list자료형보다 대체적으로 시간복잡도가 낮음

# dic = {}
# for i in nList:
#     if i in dic:
#         dic[i] += 1
#     else:
#         dic[i] = 1

# for j in mList:
#     if j in dic:
#         print(dic[j], end=' ')
#     else:
#         print(0, end=' ')
