#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,a,cntA = 0;
    vector<long long> A;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        A.push_back(a);
    }

    sort(A.begin(),A.end());
    
    long long a1 = A[0], cnt = 1;
    for(int i = 1; i < n; i++){
        if(a1 == A[i]) cnt++;
        else{
            if(cnt%2==1) cntA++; //出現奇數次才要記下來
            cnt = 1;
            a1 = A[i];
        }
    }
    if(cnt%2==1) cntA++; //最後一個數字在回圈內沒有被計算到
    cout << cntA << endl;
return 0;
}
