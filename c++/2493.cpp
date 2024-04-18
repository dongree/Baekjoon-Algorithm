#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> stack;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    arr.push_back(a);
  }

  for (int i = 0; i < N; i++) {
    if (stack.size() == 0) {
      cout << 0 << ' ';
    } else {
      if (arr[stack.back() - 1] < arr[i]) {
        while (stack.size() != 0 && arr[stack.back() - 1] < arr[i]) {
          stack.pop_back();
        }
        cout << (stack.size() == 0 ? 0 : stack.back()) << ' ';
      } else {
        cout << stack.back() << ' ';
      }
    }
    stack.push_back(i + 1);
  }

  return 0;
}