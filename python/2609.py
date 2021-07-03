# 내 풀이
a, b = map(int, input().split())


def gcd(a, b):
    k = 2
    result = 1
    c = min(a, b)

    while(k <= c):
        if(a % k == 0 and b % k == 0):
            a = a//k
            b = b//k
            result *= k
        else:
            k += 1
    return result


def lcm(a, b):
    g = gcd(a, b)
    return(a*b//g)


print(gcd(a, b))
print(lcm(a, b))

# 유클리드 호제법 풀이

# a, b = map(int, input().split())


# def gcd(a, b):
#     if b == 0:
#         return a
#     else:
#         return gcd(b, a % b)


# def lcm(a, b):
#     g = gcd(a, b)
#     return int(a*b//g)


# print(gcd(a, b))
# print(lcm(a, b))
