#include <bits/stdc++.h>
using namespace std;
int n,m;

bool comp(int a, int b){
  if(a%m == b%m){
    if(a%2 != 0 && b%2 != 0) return a > b;
    else if(a%2 == 0 && b%2 == 0) return a < b;
    else return a%2 != 0;
  }
  return a%m < b%m;
}

int main(){
  int N = 20;
  while(N--){
    cin >> n >> m;
  
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    
    sort(vec.begin(), vec.end(), comp);
    
    cout << n << " " << m << endl;
    for(int k : vec) cout << k << endl;
  }
  cout << 0 << " " << 0 << endl; 
  return 0;
}
