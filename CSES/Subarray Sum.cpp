#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long a,M = 0,cm = 0;

    for(int i = 0; i < n; i++){
        cin >> a;
        cm = max(a, cm + a);
        if(cm > M) M = cm;
    }

    cout << M << endl;
    return 0;
}
