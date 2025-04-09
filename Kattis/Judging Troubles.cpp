#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<string, int> m1,m2;
  set<string> s;
  
  string str;
  for(int i = 0; i < n; i++){
    cin >> str;
    m1[str]++;
    s.insert(str);
  }
  for(int i = 0; i < n; i++){
    cin >> str;
    m2[str]++;
  }
  
  int cnt = 0;
  for(string k : s){
    cnt += min(m1[k], m2[k]);
  }
  
  cout << cnt << endl;
  return 0;
}
