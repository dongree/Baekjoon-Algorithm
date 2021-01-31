t = int(input())

for _ in range(t):
    num = 0
    for i in input():
        if (num < 0):
            break
        else:
            if i == '(':
                num += 1
            elif i == ')':
                num -= 1
    if (num == 0):
        print('YES')
    else:
        print('NO')
