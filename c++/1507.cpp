#include <algorithm>
#include <iostream>

using namespace std;

int arr[20][20];
int answerArr[20][20];

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
      answerArr[i][j] = arr[i][j];
    }
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == k || j == k) continue;
        if (arr[i][j] > arr[i][k] + arr[k][j]) {
          cout << -1;
          return 0;
        }
        if (arr[i][j] == arr[i][k] + arr[k][j]) {
          answerArr[i][j] = 0;
        }
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      answer += answerArr[i][j];
    }
  }

  cout << answer / 2;

  return 0;
}