#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,used = 0,rw = 0;
    cin >> n;
    map<int,int> m;
    vector<int> t(n);
    for(int i = 0,a,b; i < n; i++){
        cin >> a >> b;
        m[a] = b;
        t[i] = a;
    }
    sort(t.begin(),t.end());

    for(int i = 0; i < n; i++){
        used += t[i];
        rw += m[t[i]] - used;
    }

    cout << rw << endl;
return 0;
}
