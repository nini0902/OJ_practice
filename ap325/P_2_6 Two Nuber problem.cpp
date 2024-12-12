#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL m,n,k,cnt = 0;
    cin >> m >> n >> k;
    vector<LL> A(m);
    vector<LL> B(n);
    for(int i = 0; i < m; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i = 0; i < m; i++){
        if(binary_search(B.begin(),B.end(),k-A[i])) cnt ++;
    }
    cout << cnt << endl;
return 0;
}
