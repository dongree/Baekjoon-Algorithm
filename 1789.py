s = int(input())

k = 1
result = 0

while(True):
    result += k
    if result > s:
        break
    k += 1

print(k-1)
