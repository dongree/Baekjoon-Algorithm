#include <iostream>
#include <algorithm>

using namespace std;

int arr[10000];

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  int criIdx = n;
  for(int i=n-1; i>=1; i--){
    if(arr[i]>arr[i-1]){
      criIdx = i;
      break;
    }
  }
  if(criIdx==n){
    cout << -1;
    return 0;
  }
  for(int i=n-1; i>=criIdx; i--){
    if(arr[i]>arr[criIdx-1]){
      swap(arr[i], arr[criIdx-1]);
      break;
    }
  }
  sort(arr+criIdx, arr+n);
  
  for(int i=0; i<n; i++){
    cout << arr[i] << ' ';
  }
  return 0;
}

// another solution

// #include <iostream>
// #include <algorithm>

// using namespace std;

// int arr[10000];

// int main(){
//   int n;
//   cin >> n;
//   for(int i=0; i<n; i++){
//     cin >> arr[i];
//   }
//   if(next_permutation(arr, arr+n)){
//     for(int i=0; i<n; i++){
//       cout << arr[i] << ' ';
//     }
//   }else{
//     cout << -1;
//   }
//   return 0;
// }
