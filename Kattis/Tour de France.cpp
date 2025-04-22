#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  while(1){
    cin >> n;
    if(!n) break;
    else cin >> m;
    
    vector<double> f(n), r(m);
    for(int i = 0; i < n; i++) cin >> f[i]; // 前齒輪
    for(int i = 0; i < m; i++) cin >> r[i]; // 後齒輪
    
    vector<double> ra;
    // 計算變速比
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++) ra.push_back(r[i] / f[j]); 
    }
    
    sort(ra.begin(), ra.end());
    
    double M = 0;
    //找最大的相鄰比
    for(int i = 0; i < ra.size()-1; i++){
      if(ra[i] < ra[i+1]) M = max(M, ra[i+1]/ra[i]);
    }
    
    // 輸出到小數點後兩位
    cout << fixed << setprecision(2) << M << endl;
  }
  return 0;
}
