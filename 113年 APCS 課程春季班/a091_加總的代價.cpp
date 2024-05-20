#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, x;
    while(cin >> N){
        if(N==0) break;
        priority_queue<int, vector<int>, greater<int>> PQ;
        //輸入資料(小到大排)
        for(int i = 0; i < N; i++){
            cin >> x;
            PQ.push(x);
        }
        unsigned long long cost = 0;
        while(PQ.size() != 1){
            x = PQ.top(); PQ.pop(); //小的會在top
            x += PQ.top();PQ.pop(); //將目前最小的兩個相加
            cost += x; //加到cost去
            PQ.push(x); //剛剛兩小相加的質要放回去跟下一個相加
        }
        cout << cost << endl;
    }
return 0;
}
