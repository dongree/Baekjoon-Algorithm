# 스스로 해결 X
# 구글링 참고함
# 브루트포스

# itertools에는 permutations, combination 등과 같은 유용한 것들이 있음
from itertools import permutations

n = [1, 2, 3, 4, 5, 6, 7, 8, 9]

num = list(permutations(n, 3))

t = int(input())
for _ in range(t):
    test, s, b = map(int, input().split())
    test = list(str(test))
    removed_cnt = 0

    for i in range(len(num)):
        s_cnt = b_cnt = 0
        i -= removed_cnt

        for j in range(3):
            test[j] = int(test[j])
            if test[j] in num[i]:
                if j == num[i].index(test[j]):
                    s_cnt += 1
                else:
                    b_cnt += 1

        if s_cnt != s or b_cnt != b:
            num.remove(num[i])
            removed_cnt += 1

print(len(num))
