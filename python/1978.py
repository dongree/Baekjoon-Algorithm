n = int(input())

a = list(map(int, input().split()))

count = 0

for i in a:
    flag = True
    if i == 1:
        continue
    elif i == 2:
        count += 1
    else:
        for j in range(2, i):
            if i % j == 0:
                flag = False
                break
        if flag == True:
            count += 1

print(count)
