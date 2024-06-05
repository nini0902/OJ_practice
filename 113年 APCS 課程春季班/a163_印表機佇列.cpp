#include <bits/stdc++.h>
using namespace std;

int pa[10]; // 優先權計數陣列

// 判斷是否可以列印文件
bool CanPrint(int p){
    for(int i = p+1; i <= 9; i++){
        if(pa[i] > 0) return false; // 若存在更高優先權的文件，則不能列印
    }
    return true; // 沒有更高優先權的文件，可以列印
}

int main(){
    int T, n, m;
    cin >> T; // 讀取測試案例數
    while(T--){
        cin >> n >> m; // 讀取文件數量和你的文件位置
        queue<pair<bool, int>> q; // 建立文件佇列
        memset(pa, 0, sizeof(pa)); // 初始化優先權計數陣列

        for(int i = 0, p; i < n; i++){
            cin >> p; // 讀取每個文件的優先權
            if(i == m) q.push({true, p}); // 如果是你的文件，標記為 true
            else q.push({false, p});
            pa[p]++; // 增加對應優先權級別的計數
        }

        int ans = 0; // 初始化計數器
        while(!q.empty()){
            pair<bool, int> now = q.front(); // 取出佇列的第一個文件
            q.pop(); // 將文件從佇列中移除
            if(CanPrint(now.second)){ // 檢查是否可以列印該文件
                ans++, pa[now.second]--; // 列印並增加計數器，同時減少對應優先權級別的計數
                if(now.first) break; // 如果是你的文件，停止迴圈
            }
            else q.push(now); // 否則將文件放回佇列末尾
        }
        cout << ans << endl; // 輸出你的文件被列印的順序
    }
    return 0;
}
