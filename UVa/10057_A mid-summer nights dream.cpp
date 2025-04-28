#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  
  int n;
  while(cin >> n) {
    int l,r,mid;
    vector<int> vec(n);
    for(int i = 0; i < n ; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    
    if(n & 1) { // 奇數
      l = r = n/2;
    }
    else {
      r = n/2;
      l = r-1;
    }
    
    cout << vec[l] << ' ';
    
    auto cntl = lower_bound(vec.begin(), vec.end(), vec[l]); // 陣列中合法 A 的最左索引(位置)
    auto cntr = upper_bound(vec.begin(), vec.end(), vec[r]); // 陣列中合法 A 的最右索引(位置)
    cout << cntr - cntl << ' ';
    cout << vec[r] - vec[l] + 1 << endl; // 計算 A 可以有幾種(不必在陣列裡面)
  }
  return 0;
}
