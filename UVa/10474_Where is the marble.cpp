#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,c = 1;
  
  while(1){
    cin >> n >> m;
    if(!n && !m) break;
    
    cout << "CASE# " << c << ":\n";
    c++;
    
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    
    sort(vec.begin(), vec.end());
    
    int t;
    while(m--){
      cin >> t;
      auto it = lower_bound(vec.begin(), vec.end(), t);
      if(*it == t) {
        cout << t << " found at ";
        cout << it - vec.begin()+1 << endl;
      }
      else cout << t << " not found\n";
    }
  }
  return 0;
}
