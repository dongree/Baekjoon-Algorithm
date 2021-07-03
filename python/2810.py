n = int(input())
seat = input()

cup = n + 1 - seat.count('L')//2

if n > cup:
    print(cup)
else:
    print(n)
