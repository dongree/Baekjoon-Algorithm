s = input()

alphabet = [0 for _ in range(26)]

for i in s:
    alphabet[ord(i)-97] += 1


for j in alphabet:
    print(j, end=" ")

# unpacking 방법으로도 해결 가능
# print(*alphabet)
