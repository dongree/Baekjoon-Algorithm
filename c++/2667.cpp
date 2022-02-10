// #include <iostream>
// #include <string>
// #include <queue>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int map[26][26];
// bool isVisited[26][26];
// queue<pair<int, int>> q;
// vector<int> v;

// int n, c = 0;
// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1};

// void bfs(int y, int x){
//   isVisited[y][x] = true;
//   q.push(make_pair(y, x));
//   c++;
//   while(!(q.empty())){
//     y = q.front().first;
//     x = q.front().second;
//     q.pop();
//     for(int i=0; i<4; i++){
//       int ny = y+dy[i];
//       int nx = x+dx[i];
//       if(0 <= ny && ny < n && 0 <= nx && nx < n && map[ny][nx] && !(isVisited[ny][nx])){
//         q.push(make_pair(ny, nx));
//         isVisited[ny][nx] = true;
//         c++;
//       }
//     }
//   }
// }

// int main(){
//   cin >> n;

//   for(int i=0; i<n; i++){
//     string s;
//     cin >> s;
//     for(int j=0; j<n; j++){
//       map[i][j] = s[j]-'0';
//     }
//   }
//   for(int i=0; i<n; i++){
//     for(int j=0; j<n; j++){
//       if(map[i][j]==1 && !(isVisited[i][j])){
//         c = 0;
//         bfs(i, j);
//         v.push_back(c);
//       }
//     }
//   }
  
//   sort(v.begin(), v.end());

//   cout << v.size() << '\n';
//   for(int i : v){
//     cout << i << '\n';
//   }

//   return 0;
// }


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int map[26][26];
bool isVisited[26][26];
vector<int> v;

int n, c = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int y, int x){
  isVisited[y][x] = true;
  c++;
  for(int i=0; i<4; i++){
    int ny = y+dy[i];
    int nx = x+dx[i];
    if(0 <= ny && ny < n && 0 <= nx && nx < n && map[ny][nx] && !(isVisited[ny][nx])){
      dfs(ny, nx);
    }
  }  
}

int main(){
  cin >> n;

  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    for(int j=0; j<n; j++){
      map[i][j] = s[j]-'0';
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(map[i][j]==1 && !(isVisited[i][j])){
        c = 0;
        dfs(i, j);
        v.push_back(c);
      }
    }
  }
  
  sort(v.begin(), v.end());

  cout << v.size() << '\n';
  for(int i : v){
    cout << i << '\n';
  }

  return 0;
}