# replace(a, b) a를 b로 대체!
cro = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

a = input()

for i in cro:
    a = a.replace(i, '?')

print(len(a))
