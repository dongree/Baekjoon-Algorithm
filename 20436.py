keyboardL = [['q', 'w', 'e', 'r', 't'], [
    'a', 's', 'd', 'f', 'g'], ['z', 'x', 'c', 'v']]
keyboardR = [[' ', 'y', 'u', 'i', 'o', 'p'], [
    ' ', 'h', 'j', 'k', 'l'], ['b', 'n', 'm']]


def keyboardLocation(a, leftOrRight):
    for i in range(3):
        if a in leftOrRight[i]:
            x = i
            y = leftOrRight[i].index(a)
            break
    return x, y


l, r = input().split()
string = input()

lx, ly = keyboardLocation(l, keyboardL)
rx, ry = keyboardLocation(r, keyboardR)

result = 0

for i in string:
    if i in sum(keyboardL, []):
        x, y = keyboardLocation(i, keyboardL)
        result += abs(lx-x)+abs(ly-y)+1
        lx, ly = x, y
    elif i in sum(keyboardR, []):
        x, y = keyboardLocation(i, keyboardR)
        result += abs(rx-x)+abs(ry-y)+1
        rx, ry = x, y


print(result)
