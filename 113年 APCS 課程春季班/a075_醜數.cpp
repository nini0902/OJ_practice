#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1); //收集醜數
    int i2 = 0, i3 = 0, i5 = 0, n,ugly;
    cin >> n;
    //算出n以前所有醜數
    for(int i = 1; i < n; i++){
        ugly = min(v[i2]*2, min(v[i3]*3,v[i5]*5));
        v.push_back(ugly);
        if(v[i] == v[i2]*2) i2++;
        if(v[i] == v[i3]*3) i3++;
        if(v[i] == v[i5]*5) i5++;
    }
    cout << v[n-1] << endl;
return 0;
}
