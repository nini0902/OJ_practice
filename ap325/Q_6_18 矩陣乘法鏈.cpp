#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> vec(n+1);
  for(int i = 0; i <= n; i++) cin >> vec[i];
  
  vector<vector<int>> A(n+1, vector<int>(n+1, 0));
  for(int len = 2; len <= n; len++){
    for(int i = 1; i <= n-len+1; i++){
      int j = i+len-1;
      A[i][j] = INT_MAX;
      for(int k = i; k < j; k++){ //分割所有可能性
        int Q = A[i][k] + A[k+1][j] + vec[i-1]*vec[k]*vec[j];
        if(Q < A[i][j]) A[i][j] = Q;
      }
    }
  }
  cout << A[1][n] << endl;
  return 0;
}
