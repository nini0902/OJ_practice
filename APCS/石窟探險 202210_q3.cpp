#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int idx = 1;
long long ans = 0;

void f(int x){
    int ch = 2 + x%2; //根據x判斷有2還是3個鄰
    for(int i = 0; i < ch; i++){
        int nxt = a[idx]; //下一個的大小
        idx++;
        if(nxt == 0) continue; //表示已經到底了
        ans += abs(x - nxt);
        f(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tt = 0;
    while (cin >> n){
        a.push_back(n);
        tt++;
    }

    f(a[0]);
    cout << ans << endl;
    return 0;
}
