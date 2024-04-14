#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> c(n);

    for(int i = 0; i < n; i++) cin >> c[i];

    sort(c.begin(), c.end());

    int now = c[0], cnt = now;
    for(int i = 1; i < n; i++){
        cnt += c[i]; // 先把數字加上去
        if(c[i] == c[i-1]+1) cnt -= c[i]; //如果他比上一個數字大1就扣掉他
    }

    cout << cnt << endl;
return 0;
}
