n = int(input())
peak = list(map(int, input().split()))
peak.append(100001)

i = 0
j = 1
maxNum = 0

while(j < n+1):
    if peak[i] <= peak[j]:
        if j-i-1 > maxNum:
            maxNum = j-i-1
        i = j
    j += 1

print(maxNum)
