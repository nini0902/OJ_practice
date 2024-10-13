#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<LL> pre(n+1, 0);
  for(int i = 1,x; i <= n; i++){
    cin >> x;
    pre[i] = pre[i-1] + x;
  }
  
  int s,e;
  for(int i = 0; i < m; i++){
    cin >> s >> e;
    cout << pre[e] - pre[s-1] << endl;
  }
  return 0;
}
