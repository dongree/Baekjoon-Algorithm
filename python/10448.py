t = int(input())

for i in range(t):
    tri = []
    n = int(input())
    j = 1
    while(True):
        a = j*(j+1)//2
        if (a > n):
            break
        tri.append(a)
        j += 1
    breaker = False
    for q in tri:
        for w in tri:
            for e in tri:
                if q+w+e == n:
                    breaker = True
            if breaker == True:
                break
        if breaker == True:
            print(1)
            break
    if breaker == False:
        print(0)
