import sys
input = sys.stdin.readline

n = int(input())

stackA = [0]
stackB = [i for i in range(1, n+1)]
stackB.reverse()
pushAndPop = []
flag = True

for _ in range(n):
    a = int(input())
    while(True):
        if stackA[-1] == a:
            stackA.pop()
            pushAndPop.append('-')
            break
        else:
            if len(stackB) == 0 and len(pushAndPop) != n*2:
                flag = False
                break
            stackA.append(stackB.pop())
            pushAndPop.append('+')

if flag == True:
    for i in pushAndPop:
        print(i)
else:
    print('NO')
