#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  // 輸入第一行：屬性名稱
  string line;
  getline(cin, line);
  stringstream ss(line);
  vector<string> attrs;
  string attr;
  while(ss >> attr) attrs.push_back(attr);
  int k = attrs.size();
  
  // 建立屬性->欄位索引對照表
  unordered_map<string, int> col;
  for(int i = 0; i < k; i++) col[attrs[i]] = i;
  
  // 讀取歌曲數量與內容
  int m;
  cin >> m;
  vector<vector<string>> songs(m, vector<string>(k));
  for(auto &row : songs) {
    for(auto &v : row) cin >> v;
  }
  
  // 讀取排序指令
  int n;
  cin >> n;
  
  auto print_current = [&](){
    // 輸出欄位名稱
    for(int i = 0; i < k; ++i) {
      cout << attrs[i] << (i+1 == k? '\n' : ' ');
    }
    
    // 輸出歌曲資料
    for(const auto &row : songs) {
      for(int i = 0; i < k; i++) {
        cout << row[i] << (i+1 == k? '\n' : ' ');
      }
    }
    cout << '\n';
  };
  
  // 依序執行 n 個排序後輸出
  string key;
  while(n--) {
    cin >> key;
    int idx = col[key];
    stable_sort(songs.begin(), songs.end(), [idx](const auto &a, const auto &b) {
      return a[idx] < b[idx];
    });
    print_current();
  }
  
  return 0;
}
