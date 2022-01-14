#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> trees;
  int max = 0;
  for(int i=0; i<n; i++){
    int th;
    cin >> th;
    trees.push_back(th);
    if(max < th){
      max = th;
    }
  }

  int start = 0;
  int end = max;
  int result = 0;

  while(start <= end){
    int mid = (start+end)/2;
    long long int sum = 0;
    for(int h: trees){
      if(h > mid){
        sum += h-mid;
      }
    }
    if(sum >= m){
      result = mid;
      start = mid+1;
    }
    else{
      end = mid-1;
    }
  }
  cout << result;
}