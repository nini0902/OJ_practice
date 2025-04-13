#include <bits/stdc++.h>
using namespace std;

int main(){
  int l = 0, r = 11, n;
  string s;

  while(1){
    cin >> n;
    cin.ignore();
    if(n == 0) break;
    
    getline(cin, s);
    
    if(s == "too high") r = min(r, n);
    else if(s == "too low") l = max(l, n);
    else if(s == "right on") {
      if(n < r && n > l) cout << "Stan may be honest" << endl;
      else cout << "Stan is dishonest" << endl;
      l = 0, r = 11;
    }
  }
  return 0;
}
