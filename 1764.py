# .strip(char) 문자열 양끝제거, char 지정이 없으면 공백문자 제거, 지정되어 있으면 char의 모든 조합 제거
# .rstrip(char) 문자열 오른쪽 제거, char 지정이 없으면 공백문자 제거, 지정되어 있으면 char의 모든 조합 제거
# .lstrip(char) 문자열 왼쪽 제거, char 지정이 없으면 공백문자 제거, 지정되어 있으면 char의 모든 조합 제거

import sys
input = sys.stdin.readline

n, m = map(int, input().split())

a = set()
result = []

for _ in range(n):
    a.add(input().rstrip())

for _ in range(m):
    k = input().rstrip()
    if k in a:
        result.append(k)

print(len(result))
for i in sorted(result):
    print(i)
