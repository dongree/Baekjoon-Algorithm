#include <iostream>
#include <queue>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  queue<int> q;
  for(int i=1; i<n+1; i++){
    q.push(i);
  }
  cout << '<';
  while(!q.empty()){
    for(int i=0; i<k-1; i++){
      int a = q.front();
      q.pop();
      q.push(a);
    }
    if(q.size()==1){
      cout << q.front() << '>';
    } else{
      cout << q.front() << ", ";
    }
    q.pop();
  }
  return 0;
}