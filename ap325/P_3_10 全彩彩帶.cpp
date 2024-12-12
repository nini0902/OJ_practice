#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int seq[N], cnt[N] = {0};
map<int,int> mp;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> seq[i];
        mp[seq[i]] = 0;
    }

    int tt_color = 0;
    for(auto &c : mp) c.second = tt_color++; //重新編號

    int l = 0, r = 0, n_color = 0, m = n;

    while(r < n){
        int c = mp[seq[r]];
        cnt[c]++;
        if(cnt[c] == 1) n_color++; //新的顏色
        r++;
        while(1){
            c = mp[seq[l]];
            if(cnt[c] == 1) break; //範圍內該顏色剩一個
            cnt[c]--;
            l++; //範圍左端向右移1位
        }

        if(n_color == tt_color){
            m = min(m, r-l);
        }
    }
    cout << m << endl;
    return 0;
}
