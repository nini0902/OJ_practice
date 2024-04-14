#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,cnt = 0;
    cin >> n;
    vector<long long> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    sort(c.begin(),c.end());

    for(int i = 1; i < n; i++){
        cnt += pow(c[i]-c[i-1], 2);
    }

    cout << cnt << endl;
return 0;
}
