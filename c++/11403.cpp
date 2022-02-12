// #include <iostream>

// using namespace std;

// int map[101][101];
// bool isVisited[101] = {false, };
// int result[101][101];
// int n;

// void dfs(int node, int startNode){
//   for(int i=1; i<=n; i++){
//     if(map[node][i] && !(isVisited[i])){
//       result[startNode][i] = 1;
//       isVisited[i] = true;
//       dfs(i, startNode);
//     } 
//   }
// }

// int main(){
//   cin >> n;

//   for(int i=1; i<=n; i++){
//     for(int j=1; j<=n; j++){
//       cin >> map[i][j];
//     }
//   }

//   for(int i=1; i<=n; i++){
//     for(int j=1; j<=n; j++){
//       isVisited[j] = false;
//     }
//     dfs(i, i);
//   }

//   for(int i=1; i<=n; i++){
//     for(int j=1; j<=n; j++){
//       cout << result[i][j] << " ";
//     }
//     cout << '\n';
//   }

//   return 0;
// }


// #include <iostream>
// #include <queue>

// using namespace std;

// int map[101][101];
// bool isVisited[101] = {false, };
// int result[101][101];
// queue<int> q;
// int n;

// void bfs(int node){
//   int startNode = node;
//   q.push(node);
//   while(!(q.empty())){
//     node = q.front();
//     q.pop();
//     for(int i=1; i<=n; i++){
//       if(map[node][i] && !(isVisited[i])){
//         q.push(i);
//         result[startNode][i] = 1;
//         isVisited[i] = true;
//       } 
//     }
//   }
// }

// int main(){
//   cin >> n;

//   for(int i=1; i<=n; i++){
//     for(int j=1; j<=n; j++){
//       cin >> map[i][j];
//     }
//   }

//   for(int i=1; i<=n; i++){
//     for(int j=1; j<=n; j++){
//       isVisited[j] = false;
//     }
//     bfs(i);
//   }

//   for(int i=1; i<=n; i++){
//     for(int j=1; j<=n; j++){
//       cout << result[i][j] << " ";
//     }
//     cout << '\n';
//   }

//   return 0;
// }


#include <iostream>

using namespace std;

const int INF = 1000;
int map[101][101];
int n;

int main(){
  cin >> n;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin >> map[i][j];
      if(map[i][j] == 0){
        map[i][j] = INF;
      }
    }
  }

  for(int bridge =1; bridge <= n; bridge++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        map[i][j] = min(map[i][j], map[i][bridge]+map[bridge][j]);
      }  
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(map[i][j]==INF){
        cout << 0 << ' ';
      }else{
        cout << 1 << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}
