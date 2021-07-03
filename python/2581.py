m = int(input())
n = int(input())

pnsum = 0
pnmin = 0
flag = False

for i in range(m, n+1):
    if i == 2:
        pnsum += i
        if flag == False:
            pnmin = i
            flag = True
    else:
        for j in range(2, i):
            if i % j == 0:
                break
            else:
                if j == i-1:
                    pnsum += i
                    if flag == False:
                        pnmin = i
                        flag = True

if pnsum == 0:
    print(-1)
else:
    print(pnsum)
    print(pnmin)
