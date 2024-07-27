#include <bits/stdc++.h>
using namespace std;
long long dp[55][55][55];
int N,K,M;

long long find_ans(int n, int k, int m){
    if(n < 0 || k < 0 || m < 0) return 0;
    if(dp[n][k][m] != -1) return dp[n][k][m]; //計算過就直接return 
    return dp[n][k][m] = find_ans(n-1, k, m-1) + find_ans(n-1, k-1, min(M,n-1)); 
}

int main(){
    while(cin >> N >> K >> M){
        for(int i = 0; i <= N; i++){ //目前是第i個unit
            for(int j = 0; j <= K; j++){ //i個unit內有j個bar
                for(int k = 0; k <= M; k++){ //bar最長
                    if(i == 0 || j == 0 || k == 0) dp[i][j][k] = 0; //有其中一個為0表示無解
                    else if(j == 1 && i <= k) dp[i][j][k] = 1; //只有一個bar且在合法範圍內，有一種解法
                    else dp[i][j][k] = -1; //其他就要計算
                }
            }
        }
        cout << find_ans(N,K,M) << endl;
    }
    return 0;
}
