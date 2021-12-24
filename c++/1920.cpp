#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, a;
  vector<int> v;
  bool flag;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a;
    v.push_back(a);    
  }
  sort(v.begin(), v.end());

  cin >> m;

  for(int i=0; i<m; i++){
    flag = false;
    int start = 0;
    int end = n-1;
    int mid;
    cin >> a;
    while(end-start >= 0){
      mid = (start+end)/2;
      if(v[mid] == a){
        flag = true;
        break;
      }
      else if(v[mid] < a){
        start = mid+1;
      }
      else{
        end = mid-1;
      }
    }

    if(flag){
      cout << 1 <<'\n';
    } else{
      cout << 0 << '\n';
    }
  }

  return 0;
}