#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  int n;
  vector<int> v;
  cin >> n;
    
  double mean = 0;
  
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    mean += a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  int mode = 0;
  int count = 1;
  int maxCount = 0;
  int length = v.size();

  bool flag;
  if(n == 1){
    mode = v[0];
  }else{
    for(int i=0; i<n-1; i++){   
      if(v[i] == v[i+1]){
        count += 1;
      } else{
        count = 1;
      }
      if(count > maxCount){
        maxCount = count;
        flag = true;
        mode = v[i];
      }
      else if(flag && count == maxCount){
        flag = false;
        mode = v[i];
      }      
    }
  }
  
  mean = round(mean/length);

  cout << mean << '\n';
  cout << v[length/2] << '\n';
  cout << mode << '\n';
  cout << v[length-1] - v[0] << '\n';

  return 0;
}