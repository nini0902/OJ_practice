#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n;
  
  while(n--){
    cin >> k;
    vector<int> vec(k);
    for(int i = 0; i < k; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    
    int mid = vec[k/2];
    int cnt = 0;
    for(int &i : vec) cnt += abs(mid-i);
    
    cout << cnt << endl;
  }
  return 0;
}
