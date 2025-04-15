#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> en(n), ex(m);
  map<int,int> cnt;
  
  for(int i = 0; i < n; i++) cin >> en[i];
  for(int i = 0; i < m; i++) cin >> ex[i];
  
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(en[j] < ex[i]){
        long long t = ex[i] - en[j];
        cnt[t]++;
      }
      else continue;
    }
  }
  
  int ans = 0, M = 0;
  for(const auto& k : cnt){
    if(k.second > M) {ans = k.first, M = k.second;} 
  }
  
  cout << ans << endl;
  return 0;
}
