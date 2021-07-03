# 다른 사람 풀이
# DP풀이

n = int(input())

arr = []
dp = []

for _ in range(n):
    arr.append(int(input()))

if n == 1:
    print(arr[0])
elif n == 2:
    print(arr[0]+arr[1])
else:
    dp.append(arr[0])
    dp.append(arr[0]+arr[1])
    dp.append(max(arr[0]+arr[2], arr[1]+arr[2]))

    for i in range(3, n):
        dp.append(max(dp[i-2]+arr[i], dp[i-3]+arr[i]+arr[i-1]))

    print(dp[n-1])
