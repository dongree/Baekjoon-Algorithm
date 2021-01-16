n, m = map(int, input().split())

board = []
chess = [
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW',
    'WBWBWBWB',
    'BWBWBWBW']

results = []

for _ in range(n):
    board.append((input()))

for i in range(n-7):
    for j in range(m-7):
        chess2 = []
        count = 0
        for k in range(i, i+8):
            chess2.append(board[k][j:j+8])
        for x in range(8):
            for y in range(8):
                if chess[x][y] != chess2[x][y]:
                    count += 1
        results.append(count)

print(min(64-max(results), min(results)))
