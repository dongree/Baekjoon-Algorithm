#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

struct folder {
  vector<string> folders;
  vector<string> files;
};

unordered_map<string, folder> paths;

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M;

  cin >> N >> M;

  int T = N + M;

  while (T--) {
    string P, F;
    int C;

    cin >> P >> F >> C;

    if (C) {
      if (paths.find(P) == paths.end()) {
        vector<string> folders;
        vector<string> files;
        folders.push_back(F);
        paths.insert({P, {folders, files}});
      } else {
        paths[P].folders.push_back(F);
      }
    } else {
      if (paths.find(P) == paths.end()) {
        vector<string> folders;
        vector<string> files;
        files.push_back(F);
        paths.insert({P, {folders, files}});
      } else {
        paths[P].files.push_back(F);
      }
    }
  }

  int Q;
  cin >> Q;
  while (Q--) {
    string s;
    cin >> s;

    string target;
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == '/') break;
      target = s[i] + target;
    }

    queue<string> q;
    q.push(target);
    set<string> st;
    int fileNums = 0;

    while (!q.empty()) {
      string t = q.front();
      q.pop();

      for (int i = 0; i < paths[t].folders.size(); i++) {
        q.push(paths[t].folders[i]);
      }
      fileNums += paths[t].files.size();
      for (int i = 0; i < paths[t].files.size(); i++) {
        st.insert(paths[t].files[i]);
      }
    }
    cout << st.size() << ' ' << fileNums << '\n';
  }

  return 0;
}