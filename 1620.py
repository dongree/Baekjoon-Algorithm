# 출력은 잘했으나 시간초과로 인해 다른 사람 코드 참고
#  dictionary 2개 사용하는 테크닉
# isalpha() 함수 - string이 모두 알파벳으로 되어 있을 경우 True 출력
# + isdigit() 함수 - string이 모두 digits으로 되어 있을 경우 True 출력
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

book1 = {}
book2 = {}

for i in range(1, n+1):
    a = input().rstrip()
    book1[str(i)] = a
    book2[a] = str(i)

for _ in range(m):
    k = input().rstrip()
    if k.isalpha():
        print(book2[k])
    else:
        print(book1[k])
