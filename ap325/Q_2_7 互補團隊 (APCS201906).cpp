#include <bits/stdc++.h>
using namespace std;

int string_to_bit(string s){
  int mask = 0;
  for(char c : s){
    // 把1左移 c-'A' 位(A:0, B:1 ...)
    mask |= 1 << (c-'A');
  }
  return mask;
}

int main(){
  int m,n;
  cin >> m >> n;
  vector<int> vec(n);
  
  string str;
  for(int i = 0; i < n; i++){
    cin >> str;
    vec[i] = string_to_bit(str);
  }
  
  sort(vec.begin(), vec.end());
  int cnt = 0;
  // 從第0位開始有 m 個 1
  int full = (1 << m) - 1;
  
  for(int i = 0; i < n; i++){
    auto it = lower_bound(vec.begin(), vec.end(), full-vec[i]);
    
    int a = vec[i], b = vec[it-vec.begin()];
    // (a&b) = 沒有交集(沒有重複的成員)
    // (a|b) = 完美覆蓋(聯集)
    if((a&b) == 0 && (a|b) == full) cnt++;
  }
  
  cout << cnt/2 << endl;
  return 0;
}
