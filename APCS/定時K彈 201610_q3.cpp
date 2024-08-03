#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k, ans = 0;
    cin >> n >> m >> k;

    for(int i = n-k+1; i <= n; i++){
        ans = (ans+m) % i; //約瑟夫問題_變化題
    }
    cout << ans+1 << endl;
    return 0;
}
