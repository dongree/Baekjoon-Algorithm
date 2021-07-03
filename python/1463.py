# 다른 사람 풀이
# dp 풀이
n = int(input())

dp = [0 for _ in range(n+1)]

for i in range(2, n+1):
    dp[i] = dp[i-1] + 1

    if i % 2 == 0 and dp[i] > dp[i//2]+1:
        dp[i] = dp[i//2]+1
    if i % 3 == 0 and dp[i] > dp[i//3]+1:
        dp[i] = dp[i//3]+1

print(dp[n])


# 다른사람풀이, 시간초과 되지만 좋은풀이
# n = int(input())
# numbers = {n}
# count = 0

# while 1 not in numbers:
#     new_numbers = set()
#     for i in numbers:
#         new_numbers.add(n-1)
#         if i % 2 == 0:
#             new_numbers.add(i//2)
#         if i % 3 == 0:
#             new_numbers.add(i//3)
#     count += 1
#     numbers = new_numbers

# print(count)
