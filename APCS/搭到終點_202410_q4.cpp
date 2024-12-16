#include <bits/stdc++.h>
using namespace std;

struct SEG{
  int l, r;
};

bool comp(SEG &x, SEG &y){
  return x.r < y.r; //用終點站排序
}

int main(){
  int n, m, mod;
  cin >> n >> m >> mod;
  
  vector<SEG> seg(n);
  for(int i = 0; i < n; i++) cin >> seg[i].l;
  for(int i = 0; i < n; i++) cin >> seg[i].r;
  sort(seg.begin(), seg.end(), comp);
  
  //dp計算到第i站有幾種坐法(前綴合)；point計算目前最遠的站
  vector<long long> dp(1, 1), point(1,0);
  
  for(SEG s : seg){
    if(s.r != point.back()){ //新的站
      point.push_back(s.r);
      dp.push_back(dp.back());
    }
    if(s.l == 0){
      dp.back() = (dp.back() + dp[dp.size()-2])%mod;
    }
    else{ 
      int i = lower_bound(point.begin(), point.end(), s.l)-point.begin()-1;
      dp.back() = (dp.back() + dp[dp.size()-2]-dp[i]+mod)%mod;
    }
  }
  
  long long ans;
  if(point.back() != m) ans = 0;
  else ans = (dp.back() - dp[dp.size()-2]+mod)%mod;
  cout << ans << endl;
  return 0;
}
