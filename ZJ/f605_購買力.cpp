#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d,cntd = 0,cnt = 0,M = 0,m= 100,k,a = 0;
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        a = 0, M = 0, m = 100;
        for(int j = 0; j < 3; j++){
            cin >> k;
            M = max(M,k), m = min(m,k);
            a += k;
        }
        if(M-m >= d) cntd += a/3, cnt++;
    }
    cout << cnt << " " << cntd << endl;
return 0;
}
