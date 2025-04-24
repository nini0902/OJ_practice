#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> vec(n);
  
  for(int i = 0; i < n; i++) cin >> vec[i];
  long long penalty = 0, tt = 0, p = 0;
  
  if(vec[k] <= 300) {
    penalty = vec[k];
    tt = vec[k];
    p++;
    vec[k] = INT_MAX;

    sort(vec.begin(), vec.end());
  
    for(int t : vec){
      if(tt + t <= 300){
        tt += t;
        penalty += tt;
        p++;
      }
      else break;
    }
  }
  
  cout << p << " " << penalty << endl;
  
  return 0;
}
