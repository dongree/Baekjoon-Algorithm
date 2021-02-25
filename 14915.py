# 2017 ERICA Programming
# 구글링 참고
m, n = map(int, input().split())


def convert(n, base):
    t = "0123456789ABCDEF"
    # divmod -> n을 base로 나눈 몫, 나머지 return
    q, r = divmod(n, base)
    if q == 0:
        return t[r]
    else:
        return convert(q, base) + t[r]


print(convert(m, n))
