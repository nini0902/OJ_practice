#include <bits/stdc++.h>
using namespace std;

int main(){
    int R,C,a = 1;
    cin >> R >> C;
    vector<int> r(R);
    vector<int> c(C);
    for(int i = 0; i < R; i++) cin >> r[i];
    for(int i = 0; i < C; i++) cin >> c[i];

    sort(r.begin(), r.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());

    if(r[0]!=c[0]) a = 0;
    if(a) cout << "possible" << endl;
    else cout << "impossible" << endl;
return 0;
}
