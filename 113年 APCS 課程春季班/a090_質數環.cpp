#include <bits/stdc++.h>
using namespace std;
int N;
int ans[17];
set<int> prime;
bool used[17];

//先列出範圍內所有質數
void prime_table(){
    prime.insert(2);
    for(int i = 3; i < 100; i+= 2){
        bool IsPrime = true;
        for(auto j : prime){
            if(i%j == 0) {IsPrime = false; break;}
        }
        if(IsPrime) prime.insert(i);
    }
}

void dfs(int x, int id){
    ans[id] = x;
    if(id == N-1){ //找到所有數字
        if(prime.count(x+1) == 0) return;
        for(int i = 0; i < N; i++) cout << ans[i] << " ";
        cout << endl;
        return;
    }
    for(int i = 2; i <= N; i++){
        if(used[i]) continue;
        int last = ans[id];
        if(prime.count(i+last) == 0) continue; //確認相加是不是質數
        used[i] = true;
        dfs(i, id+1);//繼續找下一個數字
        used[i] = false; //刪除現在選到的i(目的是找下一個組合)
    }
}

int main(){
    int c = 0;
    prime_table();
    while(cin >> N){
        memset(ans, 0, sizeof(ans));
        memset(used, 0, sizeof(used));
        cout << "Case " << ++c << ":\n";
        dfs(1,0);
        cout << endl;
    }
return 0;
}
