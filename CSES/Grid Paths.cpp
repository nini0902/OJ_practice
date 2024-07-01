#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; //題目要求的取模

long long find_path(vector<vector<int>>& s, int n){
    vector<vector<long long>> dp(n,vector<long long>(n,0));

    dp[0][0] = (s[0][0] == 1) ? 1:0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == 0) continue;

            if(i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD; //向下
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD; //向右
        }
    }
    return dp[n-1][n-1];
}

int main(){
    int n;
    char c;
    cin >> n;
    vector<vector<int>> s(n,vector<int>(n,0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c;
            s[i][j] = (c == '.') ? 1:0; 
        }
    }

    cout << find_path(s,n) << endl;
return 0;
}
