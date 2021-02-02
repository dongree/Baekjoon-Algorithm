n, k = map(int, input().split())

circle = [i for i in range(1, n+1)]

josephus = []
a = k-1

while(len(circle) != 0):
    josephus.append((circle.pop(a)))
    if len(circle) != 0:
        a = (a+k-1) % len(circle)

# 내 출력 코드
# print('<', end='')
# for i in range(len(josephus)):
#     if i == len(josephus)-1:
#         print(josephus[i], end="")
#     else:
#         print(josephus[i], end=", ")
# print('>')


# 다른사람 출력 코드
# sep은 print함수 안에서 구분되는 기준
# end는 print함수 출력 끝에서 구분되는 기준
# join은 문자열을 어떠한 방식으로 구분할지 정할 수 있게 해준다.
print("<", ", ".join(map(str, josephus)), ">", sep='')
