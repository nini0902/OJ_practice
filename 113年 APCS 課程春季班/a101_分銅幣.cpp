#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n, sum, half;
    cin >> m;
    vector<int> c;
    vector<int> dp;

    while(m--){
        cin >> n;
        c.resize(n);
        sum = 0, half = 0;
        for(int i = 0; i < n; i++){cin >> c[i];sum += c[i];}

        half = sum/2;
        dp.assign(half+1, 0);

        for(int i = 0; i < n; i++){
            for(int j = half; j >= c[i]; j--){
                //計算出少的那邊不超過一半最多可以是多少
                dp[j] = max(dp[j], dp[j-c[i]] + c[i]);
            }
        }
        cout << sum - dp[half]*2 << endl;
    }
    return 0;
}
