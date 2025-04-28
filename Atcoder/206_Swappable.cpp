#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  
  long long n;
  cin >> n;
  map<int,long long> freq;
  
  for(int i = 0,x; i < n ; i++) {
    cin >> x;
    ++freq[x];
  }

  long long tt = n * (n-1) / 2; // C(n 取 2) -> 總對數
  for(auto [val, f] : freq) {
    tt -= f * (f-1) / 2; // 扣掉同值對
  }
  cout << tt << endl;
  return 0;
}
