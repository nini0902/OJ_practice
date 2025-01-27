#include <bits/stdc++.h>
using namespace std;

struct temp {
  int num;
  int idx;
};

bool comp(const temp& a, const temp& b){
    return a.num < b.num;
  }

int main(){
  int n, m;
  cin >> n >> m;
  
  vector<temp> vec(n);
  for(int i = 0; i < n; i++) {cin >> vec[i].num; vec[i].idx = i+1;}
  sort(vec.begin(), vec.end(), comp);
  
  int l,r,tt; //雙指針
  for(int i = 0; i < n-2; i++){
    l = i+1, r = n-1;
    while(l < r && vec[l].num+vec[r].num+vec[i].num != m){
      tt = vec[l].num+vec[r].num+vec[i].num;
      if(tt < m) l++; //總和太小，左指針右移
      else if(tt > m) r--; //總和太大，右指針左移
    }
    //檢查指針有沒有重疊
    if(l < r && vec[l].num+vec[r].num+vec[i].num == m){
      cout << vec[i].idx << " " << vec[l].idx << " " << vec[r].idx << endl;
      break;
    }
    else if(i == n-3) cout << "IMPOSSIBLE" << endl;
  }
  //根本不夠三個數字
  if(n < 3) cout << "IMPOSSIBLE" << endl;
  return 0;
}
