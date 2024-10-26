#include <bits/stdc++.h>
using namespace std;

int main(){
  int bit;
  cin >> bit;
  
  for(int i = 0; i < (1<<bit); i++) {
    int gray = i ^ (i>>1); //gray code運算
    bitset<16> bin(gray); //轉成二進制
    cout << bin.to_string().substr(16-bit) << endl;
  }
  return 0;
}
