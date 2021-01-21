from itertools import combinations

dwarf = []

for _ in range(9):
    dwarf.append(int(input()))

cases = list(combinations(dwarf, 7))

for i in cases:
    if sum(i) == 100:
        answer = list(i)
        for j in answer:
            print(j)
        break
