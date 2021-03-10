# 최대힙, heapq
import heapq
import sys
input = sys.stdin.readline

n = int(input())

heap = []

for _ in range(n):
    x = int(input())
    if x == 0:
        if len(heap) == 0:
            print(0)
        else:
            print(-1 * heapq.heappop(heap))
    else:
        heapq.heappush(heap, -x)
