#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  long long l = 0, r = 0;
  cin >> n >> m;
  
  vector<int> vec(n);
  for(int i = 0; i < n; i++) {cin >> vec[i]; r += vec[i];}
  
  long long mid, ans = LLONG_MAX;
  l = *max_element(vec.begin(), vec.end());
  while(l <= r){
    mid = (l+r)/2;
    long long M = m, tt = 0, a = 0;
    for(int k : vec){
      if(tt + k > mid) {
        M--;
        tt = k;
        if(M == 0) {M = -1; break;}
      }
      else {
        tt += k;
      }
      a = max(a, tt);
    }
    a = max(a, tt);
    if(M >= 0){
      ans = min(ans, a);
      r = mid-1;
    }
    else l = mid+1;
  }
  cout << ans << endl;
  
  return 0;
}
