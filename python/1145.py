a = sorted(map(int, input().split()))

k = a[2]

while(True):
    count = 0
    for i in a:
        if(k % i == 0):
            count += 1
    if count >= 3:
        print(k)
        break
    k += 1
