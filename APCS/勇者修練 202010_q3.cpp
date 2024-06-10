// from : https://yuihuang.com/zj-f314/ 

#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    int a[10005], l[10005], r[10005], dp[55][10005];

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[j];
            if(j == 1) l[j] = dp[i-1][j] + a[j]; //該排第一個一定是從上一排下來的
            else l[j] = max(dp[i-1][j], l[j-1]) + a[j]; //有兩種可能，取大的
        }
        for(int j = n; j >= 1; j--){
            if(j == n) r[j] = dp[i-1][j] + a[j]; //同理上面來的
            else r[j] = max(dp[i-1][j], r[j+1]) + a[j]; //兩種可能，選大的
            dp[i][j] = max(l[j], r[j]);
        }
    }

    int ans = -1e9;
    for(int j = 1; j <= n; j++){
        ans = max(ans, dp[m][j]);
    }
    cout << ans << endl;
    return 0;
}

/*解題思路:
  目標 : 讀進來的時候，邊讀邊計算走到這個位置的最大值
  -------------------
  How? 
  1. 假設這是第一個位置，表示一定是從上面下來的，所以該位子最大值就是上面 + 他本人的值
  2. 其他的就有可能是上面or左邊or右邊來的(左右我們分開討論)
  --------
  Why 可以分開討論?
  因為題目要求不能走回頭路，表示你只要往右，你只能往右或往下(往左同理)
  藉由這個特性讓他可以兩邊分開討論
  ---------------------------
  【感謝YUI HUANG的筆記，實在太厲害了!!】
*/
