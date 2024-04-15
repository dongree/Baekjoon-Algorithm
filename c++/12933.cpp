#include <iostream>
#include <string>

using namespace std;

int arr[5];
bool isWrong = false;
int minCnt = 0;

int main() {
  freopen("example.txt", "r", stdin);

  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'q') {
      arr[0]++;
      if (minCnt > 0) minCnt -= 1;
    } else if (s[i] == 'u') {
      if (arr[0] > arr[1])
        arr[1]++;
      else {
        isWrong = true;
        break;
      }
    } else if (s[i] == 'a') {
      if (arr[1] > arr[2])
        arr[2]++;
      else {
        isWrong = true;
        break;
      }
    } else if (s[i] == 'c') {
      if (arr[2] > arr[3])
        arr[3]++;
      else {
        isWrong = true;
        break;
      }
    } else if (s[i] == 'k') {
      if (arr[3] > arr[4]) {
        arr[4]++;
        minCnt++;
      } else {
        isWrong = true;
        break;
      }
    }
  }

  int a = arr[0];
  for (int i = 1; i < 5; i++) {
    if (a != arr[i]) isWrong = true;
  }

  cout << (isWrong ? -1 : minCnt);

  return 0;
}