# Brute force문제
# 스스로 해결 X

n = int(input())

end = 666

while n:
    if '666' in str(end):
        n -= 1
    end += 1

print(end-1)
