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
        cnt += (str[i]/b); //加上這段可以放幾個長度圍b的區段
    }
    cout << cnt-a+1 << endl; //所有區段-選擇區段=未被選擇的區段，再加一則必選中
    return 0;
}
