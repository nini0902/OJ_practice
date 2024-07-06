#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    vector<int> str;
    for(int i = 0; i < n; i++) continue;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') {
            if(cnt >= b) str.push_back(cnt);
            cnt = 0;
        }
        else cnt++;
    }
    if(cnt != 0 && cnt >= b) str.push_back(cnt);

    cnt = 0;
    for(int i = 0; i < str.size(); i++) {
        cnt += (str[i]/b); //計算str[i]最多可以放幾段長度為b的區段
    }
    cout << cnt-a+1 << endl; //假設猜了cnt-a題都沒有猜中，那下一題一定可以戳到答案
    return 0;
}
