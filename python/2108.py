from collections import Counter
import sys
input = sys.stdin.readline

# collections 모듈의 Counter 클래스를 알게 됨.
# Counter(list or string)는 리스트나 문자열의 각 원소들의 개수를 사전형식으로 표현해줌.
# Counter 클래스 안에 most_common이라는 메소드도 알게 됨.
# Counter(list or string).most_common() 데이터의 개수가 많은 순으로 튜플 형식으로 이루어진 배열을 리턴함.
# .most_common(인자) 인자가 들어가면 그 숫자만큼 데이터를 리턴함.


def mean(numbers):
    return round(sum(numbers)/len(numbers))


def median(numbers):
    return numbers[len(numbers)//2]


def mode(numbers):
    a = Counter(numbers).most_common(2)
    if (len(a) >= 2 and a[0][1] == a[1][1]):
        result = a[1][0]
    else:
        result = a[0][0]
    return result


def maxMinDiff(numbers):
    return max(numbers)-min(numbers)


n = int(input())

numbers = []

for _ in range(n):
    numbers.append(int(input()))

numbers.sort()

print(mean(numbers))
print(median(numbers))
print(mode(numbers))
print(maxMinDiff(numbers))
