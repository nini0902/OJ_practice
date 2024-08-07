#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    long long b;
    cin >> n;
    vector<long long> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> b;
        auto lb = lower_bound(A.begin(), A.end(), b);
        if(lb == A.end()) lb = A.end()-1; //比最後一個大就設成結尾
        auto ub = upper_bound(A.begin(), A.end(), b);
        if(ub == A.begin()) ub = A.begin(); //比開頭小就設成開頭
        else ub--; //剩下的全部-1(upper_bound是比目標大的最小值)就是比目標小的最大值或是相等值
        
        if(abs(*lb-b) > abs(*ub-b)) cout << abs(*ub-b) << endl;
        else cout << abs(*lb-b) << endl;
    }
    return 0;
}
