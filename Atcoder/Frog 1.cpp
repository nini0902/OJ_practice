#include <bits/stdc++.h>
using namespace std;

int min_cost(const vector<int>& H){
    int n = H.size();
    if(n == 1) return 0;

    vector<int> dp(n,0);

    dp[0] = 0;
    dp[1] = abs(H[1] - H[0]);

    for(int i = 2; i < n; i++){
        int c1 = dp[i-1] + abs(H[i] - H[i-1]); //最後一格跳一格
        int c2 = dp[i-2] + abs(H[i] - H[i-2]); //最後一格跳兩格
        dp[i] = min(c1,c2);
    }
    return dp[n-1];
}

int main(){
    int N;
    cin >> N;
    vector<int> H(N);

    for(int i = 0; i < N; i++) cin >> H[i];

    cout << min_cost(H) << endl;
return 0;
}
