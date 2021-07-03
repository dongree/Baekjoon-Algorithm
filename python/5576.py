w = []
k = []

for _ in range(10):
    w.append(int(input()))

for _ in range(10):
    k.append(int(input()))

w.sort()
k.sort()

print(sum(w[7:10]), sum(k[7:10]))
