# 계수정렬
# python에서는 성공 pypy에서는 실패
# pypy가 일반적으로 python보다 효율이 좋지만 특정 프로그램에선 그 효율이 떨어질 수 있다!

import sys

input = sys.stdin.readline

n = int(input())

count = [0 for i in range(10001)]

for _ in range(n):
    a = int(input())
    count[a] += 1

for i in range(len(count)):
    for j in range(count[i]):
        print(i)
