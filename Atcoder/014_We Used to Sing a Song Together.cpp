#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
    LL n,cnt = 0;
    cin >> n;
    vector<LL> A(n);
    vector<LL> B(n);

    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    for(int i = 0; i < n; i++) cnt += abs(A[i]-B[i]);
    
    cout << cnt << endl;
return 0;
}
