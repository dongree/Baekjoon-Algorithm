# 문자열로 보는 관점
n = input()

if len(n) == 1 or len(n) == 2:
    print(int(n))
else:
    k = 99
    for i in range(100, int(n)+1):
        i = str(i)
        if int(i[1])-int(i[0]) == int(i[2])-int(i[1]):
            k += 1
    print(k)


# 수로 보는 관점
# n = int(input())

# if n < 100:
#     print(n)
# else:
#     k = 99
#     for i in range(100, n+1):
#         hund = i // 100
#         ten = (i % 100) // 10
#         one = (i % 100) % 10
#         if (hund - ten) == (ten - one):
#             k += 1
#     print(k)
