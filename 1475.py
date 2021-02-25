n = input()

a = []

for i in range(10):
    a.append(n.count(str(i)))

if a.index(max(a)) == 6 or a.index(max(a)) == 9:
    k = a[6]+a[9]
    if k % 2 == 0:
        a.append(k//2)
    else:
        a.append(k//2+1)
    a[6] = 0
    a[9] = 0

print(max(a))
