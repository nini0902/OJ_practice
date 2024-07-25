//解法來源：https://home.gamer.com.tw/artwork.php?sn=4683548

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int N;
    long long dp[201] = {}, t;
    cin >> N;

    while(N--){
        cin >> s;
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0') dp[i+1] = max(dp[i+1], dp[i]);

            else {
                t = 0;
                for(int j = i; j < s.length(); j++){
                    //t<<3 = t*8, t<<1 = t*2, 合起來就是t*10
                    t = (t<<3) + (t<<1) + s[j] - '0';

                    if(t > 2147483647) break;

                    dp[j+1] = max(dp[j+1], dp[i] + t);
                }
            }
        }
        cout << dp[s.length()] << endl;
    }
    return 0;
}
