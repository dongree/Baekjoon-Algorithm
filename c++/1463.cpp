#include <iostream>

using namespace std;

int arr[1000001];

int main(){
  int n;
  cin >> n;
  
  arr[2] = 1;
  arr[3] = 1; 
  for(int i=4; i<=n; i++){
    arr[i] = arr[i-1]+1;
    if(i%3 == 0 && arr[i/3]+1<arr[i]){
      arr[i] = arr[i/3]+1;
    }
    if(i%2 == 0 && arr[i/2]+1<arr[i]){
      arr[i] = arr[i/2]+1;
    }
  }
  
  cout << arr[n];
  
  return 0;
}