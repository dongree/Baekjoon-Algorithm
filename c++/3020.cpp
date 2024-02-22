#include <iostream>

using namespace std;

int top[500001];
int bottom[500001];

int main() {
  freopen("example.txt", "r", stdin);
  int N, H;
  cin >> N >> H;

  for (int i = 0; i < N; i++) {
    int h;
    cin >> h;
    if (i % 2 == 0) {
      bottom[h]++;
    } else {
      top[H - h + 1]++;
    }
  }

  for (int i = 1; i <= H; i++) {
    bottom[H - i] += bottom[H - i + 1];
    top[i] += top[i - 1];
  }

  int min = 1000000;
  int cnt = 0;
  for (int i = 1; i <= H; i++) {
    if (bottom[i] + top[i] < min) {
      min = bottom[i] + top[i];
      cnt = 1;
    } else if (bottom[i] + top[i] == min) {
      cnt++;
    }
  }

  cout << min << ' ' << cnt;
  return 0;
}