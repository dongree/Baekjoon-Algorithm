# 내 풀이 -> 메모리 초과

# from itertools import permutations

# n = input()
# cases = set(permutations(n))

# maximum = 0

# for i in cases:
#     result = ''
#     for j in range(len(i)):
#         result += i[j]
#     if (int(result) % 30 == 0) and (int(result) > maximum):
#         maximum = int(result)

# if maximum == 0:
#     print(-1)
# else:
#     print(maximum)

#  다른 사람 풀이
n = list(input())
n.sort(reverse=True)
result = 0

for i in n:
    result += int(i)
# 30의 배수가 되는 조건
# 1. 일의 자리수가 0,
# 2. 각 자리의 숫자를 더했을 때 3으로 나누어 떨어져야 됨
if result % 3 != 0 or "0" not in n:
    print(-1)
else:
    # ''.join(list) -> 리스트에서 문자열로 변환
    print(''.join(n))
