#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> a(47);
vector<int> b(47);
vector<int> c(47);

int main(){
    int n,k;
    LL cnt = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> k;
        a[k%46]++; //可能有多個數同餘
    }
    for(int i = 0; i < n; i++){
        cin >> k;
        b[k%46]++;
    }
    for(int i = 0; i < n; i++){
        cin >> k;
        c[k%46]++;
    }

    for(int x = 0; x < 46; x++){
        for(int y = 0; y < 46; y++){
            cnt += (LL)a[x] * b[y] * c[(46-(x+y)%46)%46]; //凡出現任何0即甚麼都沒加
        }
    }

    cout << cnt << endl;
return 0;
}
