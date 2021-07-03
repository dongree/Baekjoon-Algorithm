# python3로 실행시 실패
# pypy3로 실행시 성공

n = int(input())

a = []

for _ in range(n):
    a.append(int(input()))


for i in sorted(a):
    print(i)
