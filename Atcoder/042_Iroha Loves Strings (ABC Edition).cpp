#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,l;
  cin >> n >> l;
  vector<string> S(n);
  
  for(int i = 0; i < n; i++) cin >> S[i];
  sort(S.begin(), S.end());
  
  for(string s : S) cout << s;
  cout << endl;
  return 0;
}
