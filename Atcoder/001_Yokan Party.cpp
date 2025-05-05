#include <bits/stdc++.h>
using namespace std;

bool can_cut(const vector<int>& vec, int m, int min_len) {
  int last = 0, cnt = 0;
  for(int i = 1; i < vec.size(); i++) {
    if(vec[i] - last >= min_len) {
      cnt++;
      last = vec[i];
    }
  }
  return cnt >= m+1;
}

int main(){
  int n, m, r;
  cin >> n >> r;
  vector<int> vec(n+2);
  vec[0] = 0, vec[n+1] = r;
  
  cin >> m;
  for(int i = 1; i <= n; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  
  int l = 1, hi = r, ans = 0;
  while(l <= hi) {
    int mid = (l+hi) / 2;
    if(can_cut(vec, m, mid)) {
      ans = mid;
      l = mid+1;
    }
    else hi = mid-1;
  }
  
  cout << ans << endl;
  return 0;
}
