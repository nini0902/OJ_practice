#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, c = 1;
  cin >> n;
  
  int k;
  while(n--){
    cin >> k;
    int G[k];
    map<int,int> mp;
    for(int i = 0; i < k; i++){
      cin >> G[i];
      mp[G[i]]++;
    }
    for(int i = 0; i < k; i++){
      if(mp[G[i]] == 1){
        cout << "Case #" << c << ": " << G[i] << endl;
        c++;
        break;
      }
    }
  }
  return 0;
}
