n = int(input())

if(n % 5 == 0):
    print(n//5)
else:
    a = []
    for i in range(0, n, 5):
        if((n-i) % 3 == 0):
            a.append(i//5+(n-i)//3)
    if a == []:
        print(-1)
    else:
        print(min(a))
