while(True):
    a = list(map(int, input().split()))
    if(a[0] == -1):
        break
    count = 0
    a = sorted(a[0:len(a)-1])

    for i in range(len(a)):
        for j in range(i+1, len(a)):
            if a[i]*2 == a[j]:
                count += 1

    print(count)
