#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
  LL m,n,k;
  cin >> m >> n >> k;
  vector<LL> A(m), B(n);
  for(int i = 0; i < m; i++) cin >> A[i];
  for(int i = 0; i < n; i++) cin >> B[i];
  
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  
  int cnt = 0;
  for(int i = 0; i < m; i++){
    auto it = lower_bound(B.begin(), B.end(), k - A[i]);
    if(*it + A[i] == k) cnt++;
  }
  
  cout << cnt << endl;
  return 0;
}
