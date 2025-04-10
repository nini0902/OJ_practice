#include <bits/stdc++.h>
using namespace std;

bool comp(const string &a, const string &b){
  if(a[0] != b[0]) return a[0] < b[0];
  else if (a[1] != b[1]) return a[1] < b[1];
  return false;
}

int main(){
  int n;

  while(1){
    cin >> n;
    if (n == 0) break;
    
    vector<string> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];

    stable_sort(vec.begin(), vec.end(), comp);
  
    for(string s : vec) cout << s << endl;
    cout << endl;
  }
  return 0;
}
