#include <bits/stdc++.h>
using namespace std;

int main(){
  int d,n,m;
  cin >> d >> n >> m;
  vector<int> N(n+1, 0),M(m);
  N[0] = 0, N[n] = d; // 店面1的位置
  
  for(int i = 1; i < n; i++) cin >> N[i];
  for(int i = 0; i < m; i++) cin >> M[i];
  
  sort(N.begin(), N.end());
  sort(M.begin(), M.end());
  
  long long ans = 0;
  for(int i = 0; i < m; i++){
    auto it = lower_bound(N.begin(), N.end(), M[i]);
    long long r_dist = LLONG_MAX, l_dist = LLONG_MAX;
    
    if(it != N.end()) {
      r_dist = (M[i]-*it+d)%d;
      r_dist = min(r_dist, d - r_dist);
    }
    
    if(it != N.begin()) {
      --it;
      l_dist = (M[i] - *it + d)%d;
      l_dist = min(l_dist, d - l_dist);
    }

    ans += min(r_dist, l_dist);
  }
  
  cout << ans << endl;
  return 0;
}
