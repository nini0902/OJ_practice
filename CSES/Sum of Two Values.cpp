#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,yn = 0,t = 1,t1 = 1;
    long long x;
    cin >> n >> x;
    vector<long long> vec(n+1);
    vector<int> B(n+1,0);
    int l = 0, r = n;

    for(int i = 1; i <= n; i++){
        cin >> vec[i]; //輸入數據
    }

    int m = r;
    while(t1){
        l++, r = m;
        if(l >= m) t1 = 0; //如果右邊值 < 左邊值
        while(t){
            if(vec[l] + vec[r] == x){
                m = r-1, yn = 1,t = 0;
                if(B[vec[l]]==0 && B[vec[r]]==0) cout << l << " " << r << " ";
                B[vec[l]] = 1, B[vec[r]] = 1;
            }
            else{
                r--;
                if(r <= l) t = 0; //右邊碰到左邊
            }
        }
        t = 1;
    }

    if(!yn) cout << "IMPOSSIBLE";
    cout << endl;
return 0;
}
