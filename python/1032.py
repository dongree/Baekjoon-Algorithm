a = int(input())

c = ''

for i in range(a):
    b = input()
    if (i == 0):
        result = b
    else:
        for j in range(len(b)):
            if(b[j] != result[j]):
                c += '?'
            else:
                c += b[j]
        result = c
        c = ''

print(result)
