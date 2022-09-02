#include <iostream>
#include <vector>

using namespace std;

vector<long long> v;

int gcd(int a, int b){
  int c;
  while(b!=0){
    c=a%b;
    a=b;
    b=c;
  }
  return a;
}

int main(){
  int n;
  cin >> n;
  long long a;
  while(n--){
    cin >> a;
    v.push_back(a);
  }
  int k = v[1]-v[0];
  for(int i=1; i<v.size()-1; i++){
    k = gcd(k,v[i+1]-v[i]);
  }

  int result=0;
  for(int i=0; i<v.size()-1; i++){
    result += ((v[i+1]-v[i])/k-1);
  }
  cout << result;
  
  return 0;
}