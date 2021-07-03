t = int(input())

for _ in range(t):
    n = int(input())
    unives = []
    for _ in range(n):
        univ, drinkNum = input().split()
        unives.append((univ, drinkNum))
    drink = 0
    for i in unives:
        if int(i[1]) > drink:
            kingUniv = i[0]
            drink = int(i[1])
    print(kingUniv)
