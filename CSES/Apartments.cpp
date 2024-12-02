#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,k,i = 0, j = 0;
  cin >> n >> m >> k;
  
  vector<int> app(n), apa(m); //app:applicant, apa: apartment
  for(int i = 0; i < n; i++) cin >> app[i];
  for(int i = 0; i < m; i++) cin >> apa[i];
  
  sort(app.begin(), app.end());
  sort(apa.begin(), apa.end());
  
  //Two pointers
  int ans = 0;
  while(i < n && j < m){
    if(abs(app[i]-apa[j]) <= k){
      ans++; //配對成功
      i++; //下一位買家
      j++; //下一棟公寓
    }
    else if(app[i] < apa[j]-k){
      i++;
    }
    else j++;
  }
  cout << ans << endl;
  return 0;
}
