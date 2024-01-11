#include <climits>
#include <iostream>

using namespace std;

int n, m, b;
int arr[501][501];
int answerTime = INT_MAX;
int answerHeight = 0;

int main() {
  freopen("example.txt", "r", stdin);

  cin >> n >> m >> b;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  for (int h = 0; h <= 256; h++) {
    int createCnt = 0;
    int removeCnt = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int gap = arr[i][j] - h;
        if (gap < 0)
          createCnt -= gap;
        else
          removeCnt += gap;
      }
    }

    if (createCnt - removeCnt <= b) {
      int time = 2 * removeCnt + createCnt;
      if (time <= answerTime) {
        answerHeight = h;
        answerTime = time;
      }
    }
  }

  cout << answerTime << ' ' << answerHeight;

  return 0;
}