#include <bits/stdc++.h>
using namespace std;
int n,m;

bool comp(const string& a, const string& b){
  for(int i = 0; i < n; i++){
    char ca = tolower(a[i]);
    char cb = tolower(b[i]);
    if(ca != cb) return ca < cb;
  }
  return false;
}

int main(){
  
  while(1){
    cin >> n >> m;
    if(!n && !m) break;
    
    string s;
    vector<string> col(m);
    for(int i = 0; i < n; i++){
      cin >> s;
      for(int j = 0; j < m; j++) col[j] += s[j];
    }
    
    sort(col.begin(), col.end(), comp);
    
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cout << col[j][i];
      }
      cout << endl;
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
