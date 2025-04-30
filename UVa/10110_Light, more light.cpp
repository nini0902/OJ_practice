#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n;
  
  while(cin >> n){
    if(!n) break;
    
    int root = sqrt(n);
    // 平方根的時候，n 的因數會有 1, root, n(奇數)
    if(root * root == n) cout << "yes\n";
    else cout << "no\n"; // 其他的因數會成雙成對出現
  }
  return 0;
}
