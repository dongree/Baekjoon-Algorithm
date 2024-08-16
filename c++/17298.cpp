#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> v;
stack<int> st;
int result[1000000];

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    v.push_back(a);
    result[i] = -1;
  }

  for (int i = 0; i < N; i++) {
    while (!st.empty() && v[i] > v[st.top()]) {
      result[st.top()] = v[i];
      st.pop();
    }
    st.push(i);
  }

  for (int i = 0; i < N; i++) {
    cout << result[i] << ' ';
  }

  return 0;
}