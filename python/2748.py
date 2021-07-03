# 풀이 1
# n = int(input())

# array = [0 for i in range(91)]


# def fibonacci(n):
#     if n == 0:
#         return 0
#     elif n == 1:
#         return 1
#     elif array[n] != 0:
#         return array[n]
#     array[n] = fibonacci(n-1) + fibonacci(n-2)
#     return array[n]


# print(fibonacci(n))

# 풀이 2
n = int(input())

array = [0 for i in range(91)]

array[1] = 1

for i in range(2, n+1):
    array[i] = array[i-1] + array[i-2]

print(array[n])
