#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k,cnt = 0;
    cin >> n;
    vector<long long> a(n);

    cin >> a[0];
    if(a[0]%n==0) cnt++;

    for(int i = 1; i < n; i++){ //前綴和 + 判斷能不能被整除
        cin >> k;
        a[i] = a[i-1]+k;
        if(a[i]%5==0) cnt++;
    }

    for(int i = 0; i < n; i++){
        if((a[n-1]-a[i])%n==0) cnt++;
    }

    cout << cnt << endl;

return 0;
}
