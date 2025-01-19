#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> vec(n);
  
  long long sum = 0;
  for(int i = 0; i < n; i++) cin >> vec[i];
  
  sort(vec.begin(), vec.end());
  
  for(int i = 0; i < n; i++){
    if(vec[i] > sum+1) break; //沒辦法接續前面的數字
    sum += vec[i];
  }
  cout << sum+1 << endl;
  return 0;
}
