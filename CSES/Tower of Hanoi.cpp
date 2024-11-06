#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int l, int mid, int r){
  //l = 起始，mid = 過渡，r = 最終目標
  if(n == 1) cout << l << " " << r << endl; //只有一個，直接搬到右邊
  else{
    hanoi(n-1, l, r, mid); //除了最底下那個，其他的搬到間(過渡用)
    cout << l << " " << r << endl;
    hanoi(n-1, mid, l, r); //原本暫時被搬到中間過渡的，搬回去最左邊
  }
}

int main(){
  int n;
  cin >> n;
  cout << pow(2, n)-1 << endl;
  hanoi(n, 1, 2, 3);
  return 0;
}
