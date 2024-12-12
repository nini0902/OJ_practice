#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,tt = 0;
    cin >> n;

    for(int i = 0,m; i < n; i++){
        cin >> m;
        tt += (m/50), m = m%50;
        tt += (m/10), m = m%10;
        tt += (m/5), m = m%5;
        tt += m;
        cout << tt << endl;
        tt = 0;
    }
    return 0;
}
