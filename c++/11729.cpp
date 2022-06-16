#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int via){
  if(n==1) cout << from << " " << to << '\n';
  else{
    hanoi(n-1, from, via, to);
    cout << from << " " << to << '\n';
    hanoi(n-1, via, to, from);
  }
}

int main(){
  int n;
  cin >> n;
  int k = 1;
  for(int i=0; i<n; i++){
    k*=2;
  }
  k-=1;
  cout << k << '\n';
  hanoi(n,1,3,2);
}