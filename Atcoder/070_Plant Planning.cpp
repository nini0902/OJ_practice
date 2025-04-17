#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<LL> x(n), y(n);
  
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  
  LL mid_x = x[n/2];
  LL mid_y = y[n/2];
  
  LL cnt = 0;
  for(LL &i : x) cnt += abs(i - mid_x);
  for(LL &i : y) cnt += abs(i - mid_y);
  
  cout << cnt << endl;
  return 0;
}
