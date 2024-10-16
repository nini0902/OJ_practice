#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int M = 0, cnt = 0;;
  char nc;
  for(char c : s){
    if(cnt == 0) {nc = c; cnt = 1; continue;}
    if(nc == c) cnt++;
    else {nc = c; M = max(M,cnt); cnt = 1;}
  }
  cout << M << endl;
  return 0;
}
