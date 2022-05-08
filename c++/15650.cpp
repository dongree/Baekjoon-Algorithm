// #include <iostream>

// using namespace std;

// int n, m;
// int arr[9];
// bool isVisited[9] = {false,};

// void dfs(int cnt){
//   if(cnt==m){
//     for(int i=0; i<m; i++){
//       cout << arr[i] << ' ';
//     }
//     cout << '\n';
//     return;
//   }
//   for(int i=1; i<=n; i++){
//     if(!isVisited[i]){
//       for(int j=1; j<=i; j++){
//         isVisited[j] = true;
//       }
//       arr[cnt]=i;
//       dfs(cnt+1);
//       for(int j=1; j<=i; j++){
//         isVisited[j] = false;
//       }
//     }
//   }
// }

// int main(){
//   cin >> n >> m;
//   dfs(0);
//   return 0;
// }

#include <iostream>

using namespace std;

int n, m;
int arr[9];

void dfs(int num, int cnt){
  if(cnt==m){
    for(int i=0; i<m; i++){
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for(int i=num; i<=n; i++){
      arr[cnt]=i;
      dfs(i+1, cnt+1);
  }
}

int main(){
  cin >> n >> m;
  dfs(1, 0);
  return 0;
}