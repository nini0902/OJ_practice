#include <bits/stdc++.h>
using namespace std;

bool div(int n, int k, vector<int>& vec){
    vector<bool> dp(k,false);
    dp[(vec[0]%k+k)%k] = true; //第一個數字

    for(int i = 1;i < n; i++){
        vector<bool> ndp(k,false);
        int pos = vec[i]%k;
        int neg = pos * -1;
        for(int j = 0; j < k; j++){
            if(dp[j]){ //true表示有這個數字
                ndp[(j + pos + k)%k] = true; //加
                ndp[(j + neg + k)%k] = true; //減
            }
        }
        swap(dp,ndp);
    }
    return dp[0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, k;;
    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> n >> k;
        vector<int> vec(n);
        for(int i = 0; i < n; i++){
            cin >> vec[i];
        }

        if(div(n,k,vec)) cout << "Divisible" << endl;
        else cout << "Not divisible" << endl;
    }
    return 0;
}
