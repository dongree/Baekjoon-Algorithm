#include <iostream>
#include <vector>

using namespace std;

int main(){
  int k, n;
  cin >> k >> n;

  int max = 0;
  vector<int> v;
  for(int i=0; i<k; i++){
    int a;
    cin >> a;
    v.push_back(a);
    if(a > max){
      max = a;
    }
  }
  
  long long start = 1;
  long long end = max;
  long long result;
  while(start <= end){
    long long sum = 0;
    long long mid = (start+end)/2;
    for(int h : v){
      sum += h/mid;
    }
    if(sum >= n){
      start = mid+1;
      result = mid;
    } else{
      end = mid-1;
    }
  }
  cout << result;
  return 0;
}