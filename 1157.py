# set함수 count함수 안 쓴 버전

word = input().upper()
a = []
b = []

for i in range(len(word)):
    if word[i] in a:
        b[a.index(word[i])] += 1
    else:
        a.append(word[i])
        b.append(1)

k = 0
count = 0
index = 0
for i in range(len(b)):
    if(b[i] == max(b)):
        count += 1
    if(count == 2):
        break
    if(b[i] > k):
        k = b[i]
        index = i

if(count == 2):
    print('?')
elif(count == 1):
    print(a[index])

# set함수 count함수 쓴 버전
word = input().upper()
a = list(set(word))
b = []

for i in a:
    b.append(word.count(i))

if(b.count(max(b)) != 1):
    print('?')
else:
    print(a[b.index(max(b))])
