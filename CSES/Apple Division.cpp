#include <bits/stdc++.h>
using namespace std;
long long sum = 0, ans = LLONG_MAX;
int n;
vector<int> vec;

void cnt(int i, long long nsum){
  if(i == n) {
    ans = min(ans, abs(sum - 2*nsum)); //計算最小兩堆差
    return; //記得要終止不然會無限迴圈
  } 
  cnt(i+1, nsum+vec[i]); //放入第一堆
  cnt(i+1, nsum); //放入第二堆
}

int main(){
  cin >> n;
  vec.resize(n);
  
  for(int i = 0; i < n ; i++) {cin >> vec[i]; sum += vec[i];}
  
  cnt(0, 0);
  cout << ans << endl;
  return 0;
}
