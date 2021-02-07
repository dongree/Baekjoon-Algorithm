n = int(input())

money = [500, 100, 50, 10, 5, 1]
k = 1000-n
count = 0

for i in money:
    count += k // i
    k = k % i

print(count)
