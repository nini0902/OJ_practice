#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long a,M = -1e9,cm = -1e9;

    for(int i = 0; i < n; i++){
        cin >> a;
        cm = max(a, cm + a); //決定要不要結束上一段
        if(cm > M) M = cm;
    }

    cout << M << endl;
    return 0;
}
