#include <algorithm>
#include <iostream>

using namespace std;

int lectureM[100000];

int main() {
  freopen("example.txt", "r", stdin);
  int N, M;
  cin >> N >> M;

  int start = 0;
  int end = 0;

  for (int i = 0; i < N; i++) {
    cin >> lectureM[i];
    start = max(start, lectureM[i]);
    end += lectureM[i];
  }

  while (start <= end) {
    int mid = (start + end) / 2;

    int bluelayCnt = 1;
    int mCnt = 0;
    for (int i = 0; i < N; i++) {
      if (mCnt + lectureM[i] > mid) {
        mCnt = 0;
        bluelayCnt++;
      }
      mCnt += lectureM[i];
    }

    if (bluelayCnt <= M)
      end = mid - 1;
    else
      start = mid + 1;
  }

  cout << start;

  return 0;
}