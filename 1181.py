n = int(input())

a = []

for _ in range(n):
    a.append(input())

b = list(set(a))

for i in range(len(b)):
    for j in range(0, len(b)-i-1):
        if len(b[j]) > len(b[j+1]):
            box = b[j]
            b[j] = b[j+1]
            b[j+1] = box
        elif len(b[j]) == len(b[j+1]):
            for k in range(len(b[j])):
                if ord(b[j][k]) < ord(b[j+1][k]):
                    break
                elif ord(b[j][k]) > ord(b[j+1][k]):
                    box = b[j]
                    b[j] = b[j+1]
                    b[j+1] = box
                    break

for i in b:
    print(i)

# 다른 사람 풀이
# words_num = int(input())
# words_list = []

# for _ in range(words_num):
#     word = str(input())
#     word_count = len(word)
#     words_list.append((word, word_count))

# #중복 삭제
# words_list = list(set(words_list))

# #단어 숫자 정렬 > 단어 알파벳 정렬
# words_list.sort(key = lambda word: (word[1], word[0]))

# for word in words_list:
#     print(word[0])
