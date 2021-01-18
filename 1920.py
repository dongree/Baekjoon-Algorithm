# 이분탐색
# https://chancoding.tistory.com/44 참고해서 해결함

n = int(input())
N = sorted(map(int, input().split()))
m = int(input())
M = list(map(int, input().split()))


def binary(l, N, start, end):
    if start > end:
        return 0
    m = (start+end)//2
    if l == N[m]:
        return 1
    elif l < N[m]:
        return binary(l, N, start, m-1)
    else:
        return binary(l, N, m+1, end)


for l in M:
    start = 0
    end = len(N)-1
    print(binary(l, N, start, end))

# 집합 자료형 활용

# n = int(input())
# a = set(map(int, input().split()))
# # set의 시간복잡도 O(1)   list의 시간복잡도 O(2)
# m = int(input())
# b = list(map(int, input().split()))

# for i in b:
#     if i in a:
#         print(1)
#     else:
#         print(0)
