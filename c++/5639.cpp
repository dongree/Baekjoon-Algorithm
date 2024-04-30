#include <iostream>

using namespace std;

int tree[10000];

void postorder(int start, int end) {
  if (start >= end) return;
  if (start == end - 1) {
    cout << tree[start] << '\n';
    return;
  }
  int idx = start + 1;
  while (idx < end) {
    if (tree[start] < tree[idx]) break;
    idx++;
  }
  postorder(start + 1, idx);
  postorder(idx, end);
  cout << tree[start] << '\n';
}

int main() {
  freopen("example.txt", "r", stdin);

  int num;
  int idx = 0;

  while (cin >> num) {
    tree[idx++] = num;
  }
  postorder(0, idx);

  return 0;
}