#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N, cnt = 0;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N);
    vector<long long> C(N);
    map<long long,long long> cntA;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        cntA[A[i]]++; //計算這個數字在A出現幾次
    }
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];

    for(int i = 0; i < N; i++){
        cnt += cntA[B[C[i]-1]]; //加這個數字出現的次數(不用判斷是因為如果沒有相同的出現次數就是0)
    }

    cout << cnt << endl;
return 0;
}
