n = int(input())

result = 0

for i in range(max(0, n - 9*len(str(n))), n):
    length = len(str(i))
    result = i
    i = str(i)
    for j in range(length):
        result += int(i[j])
    if (result == n):
        print(i)
        break

if (result != n):
    print(0)
