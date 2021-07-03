n = input()

mid = len(n)//2

a = n[:mid]
b = n[mid:]

sumA = 0
sumB = 0

for i in a:
    sumA += int(i)
for j in b:
    sumB += int(j)

if sumA == sumB:
    print('LUCKY')
else:
    print('READY')
