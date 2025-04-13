#include <bits/stdc++.h>
using namespace std;
vector<int> h, w;
int n,k;

bool check(int max_h){
  int cnt = 0;
  for(int i = 0, j = 0; i < n; i++){
    if(h[i] >= max_h){ //檢查高度+紀錄寬度
      cnt++;
      if(cnt >= w[j]){ //可以貼第j張海報
        cnt = 0; 
        j++; 
        if(j >= k) return true; //所有的海報都能貼
      }
    }
    else cnt = 0;
  }
  return false;
}

int main(){
  cin >> n >> k;
  
  h.resize(n), w.resize(k);
  for(int i = 0; i < n; i++) cin >> h[i];
  for(int i = 0; i < k; i++) cin >> w[i];
  
  int l = 0,mid;
  int r = *max_element(h.begin(), h.end());
  int ans = 0;
  
  while(l <= r){ // <= 避免沒有檢查到最後一個r
    mid = (l+r) / 2;
    if(check(mid)){
      ans = mid;
      l = mid+1;
    }
    else{
      r = mid-1;
    }
  }
  
  cout << ans << endl;
  return 0;
}
