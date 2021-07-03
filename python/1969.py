n, m = map(int, input().split())

a = []
newcleo = ['A', 'C', 'G', 'T']
minDNA = ''
count = 0

for _ in range(n):
    a.append(input())

for i in range(m):
    b = [0, 0, 0, 0]
    for j in a:
        for k in newcleo:
            if j[i] == k:
                b[newcleo.index(k)] += 1
    minDNA += newcleo[b.index(max(b))]
    count += max(b)

minHammingDistance = m*n - count

print(minDNA)
print(minHammingDistance)
