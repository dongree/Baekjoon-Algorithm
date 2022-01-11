// #include <iostream>
// #include <queue>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main(){
//   int t;
//   cin >> t;
//   for(int i=0; i<t; i++){
//     int n, m;
//     vector<int> importance;
//     vector<int> sortedImportance;
//     queue<int> files;

//     cin >> n >> m;
//     for(int j=0; j<n; j++){
//       int a;
//       cin >> a;
//       importance.push_back(a);
//       sortedImportance.push_back(a);
//       if(j==m){
//         files.push(1);
//       }else{
//         files.push(0);
//       }
//     }
//     sort(sortedImportance.begin(), sortedImportance.end());
//     int index = 0;
//     int count = 0;
//     while(true){
//       if(importance[index] < sortedImportance.back()){
//         importance.push_back(importance[index]);
//         index += 1;
//         int front = files.front();
//         files.pop();
//         files.push(front);
        
//       } else{
//         sortedImportance.pop_back();
//         count += 1;
//         index += 1;
//         if(files.front() == 1){
//           break;
//         }
//         files.pop();
//       }
//     }
//     cout << count << '\n';

//   }
//   return 0;
// }

#include <iostream>
#include <queue>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for(int j=0; j<n; j++){
      int a;
      cin >> a;
      q.push(make_pair(j, a));
      pq.push(a);
    }
    int count = 0;
    while(!q.empty()){
      int index = q.front().first;
      int value = q.front().second;
      if(value == pq.top()){
        pq.pop();
        q.pop();
        count++;
        if(index == m){
          cout << count << '\n';
          break;
        }
      } else{
        q.push(q.front());
        q.pop();
      }
    }
  }
  return 0;
}