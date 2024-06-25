#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<string> v;
bool isVisited[10];
unordered_set<string> st;
int n, k;

void dfs(int cnt, string s) {
  if (cnt == k) {
    st.insert(s);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!isVisited[i]) {
      isVisited[i] = true;
      dfs(cnt + 1, s + v[i]);
      isVisited[i] = false;
    }
  }
}

int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }

  dfs(0, "");

  cout << st.size();

  return 0;
}