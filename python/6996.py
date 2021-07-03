t = int(input())

for _ in range(t):
    a, b = input().split()
    aa = sorted(a)
    bb = sorted(b)
    if (aa == bb):
        print('%s & %s are anagrams.' % (a, b))
    else:
        print('%s & %s are NOT anagrams.' % (a, b))
