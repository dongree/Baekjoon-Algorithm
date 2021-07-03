n = input()

n = sorted(n, reverse=True)
a = ''

for i in n:
    a += i

print(int(a))
