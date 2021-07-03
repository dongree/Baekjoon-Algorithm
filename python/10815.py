import sys
input = sys.stdin.readline

n = int(input())
nList = list(map(int, input().split()))
m = int(input())
mList = list(map(int, input().split()))

nList.sort()

# 함수 방식


def binary_search(array, start, end, target):
    while(start <= end):
        mid = (start+end)//2
        if array[mid] == target:
            return True
        elif array[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
    return False


for i in mList:
    start = 0
    end = n-1
    flag = binary_search(nList, start, end, i)
    if flag:
        print(1, end=' ')
    else:
        print(0, end=' ')


# 함수 x 방식
# for i in mList:
#     start = 0
#     end = n-1
#     flag = False
#     while(start <= end):
#         mid = (start+end)//2
#         if nList[mid] == i:
#             flag = True
#             break
#         elif nList[mid] < i:
#             start = mid + 1
#         else:
#             end = mid - 1
#     if flag:
#         print(1, end=' ')
#     else:
#         print(0, end=' ')
