a, b = input().split()

lengthDiff = len(b) - len(a)
differences = []

for i in range(lengthDiff+1):
    count = 0
    partB = b[i:len(a)+i]
    for j in range(len(a)):
        if a[j] != partB[j]:
            count += 1
    differences.append(count)

print(min(differences))
