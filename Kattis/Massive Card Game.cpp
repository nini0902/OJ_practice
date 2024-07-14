//二分搜 binary search
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, l, r;;
    cin >> n;
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(c, c+n);

    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> l >> r;

        if((l == r) && (l < c[0] || r > c[n-1])){
            cout << 0 << endl;
        }
        else{
            auto L = lower_bound(c,c+n,l); //找頭
            auto R = upper_bound(c,c+n,r); //找尾

            l = L-c, r = R-c; //把L跟R回傳的迭代器轉換成位子

            cout << r-l << endl;
        }
    }
    return 0;
}
