#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n;
  while(n--) {
    cin >> m;
    int k, valid = 1;
    for(int i = 0; i < m; i++){
      cin >> k;
      // 計算有多少元素排序符合預期
      if(k == valid) {valid++;}
    }
    cout << m-valid+1 << endl;
  }
  return 0;
}
