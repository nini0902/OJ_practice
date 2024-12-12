#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
    int n;
    long long sum = 0;
    cin >> n;
    priority_queue<LL,vector<LL>, greater<LL>> PQ;
    for(int i = 0,a; i < n; i++){
        cin >> a;
        sum += a; //計算總人數
        PQ.push(a);
    }
    
    long long cost = 0;
    while(PQ.size() > 1){
        //取出最小的兩個
        LL p1 = PQ.top(); PQ.pop();
        LL p2 = PQ.top(); PQ.pop();
        cost += p1+p2;
        PQ.push(p1+p2);    
    }

    cout << sum << endl;
    cout << cost << endl;
    return 0;
}
