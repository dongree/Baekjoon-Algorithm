# 다른 사람 코드 보고 품
# 반복적으로 봐야겠음!

n = int(input())
t = []
p = []
dp = []
for i in range(n):
    a, b = map(int, input().split())
    t.append(a)
    p.append(b)
    dp.append(b)
dp.append(0)
for i in range(n-1, -1, -1):
    if t[i] + i > n:
        dp[i] = dp[i+1]
    else:
        dp[i] = max(dp[i+1], p[i]+dp[t[i]+i])
print(dp[0])
