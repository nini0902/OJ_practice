//P_3_1 樹的高度與根 (bottom-up) 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, sum = 0;
    cin >> N;
    int h[N+1] = {0}; //計算高度
    int ch_num[N+1]; //孩子數量
    int p[N+1] = {0}; //家長是誰
    queue<int> Q;

    for(int i = 1; i <= N; i++){
        cin >> ch_num[i]; //讀入小孩的數量
        if(ch_num[i] == 0) Q.push(i); //是輩分最小的小孩
        for(int j = 0,ch; j < ch_num[i]; j++){
            cin >> ch;
            p[ch] = i;
        }
    }

    while(!Q.empty()){
        int q = Q.front();
        Q.pop();
        int P = p[q];
        sum += h[q];
        if(P == 0) {cout << q << endl; break;} //root
        h[P] = max(h[P], h[q]+1); //檢查家長的最長子孫隔幾代
        if(--ch_num[P] == 0) Q.push(P); //下面沒有小孩，換P進去Q
    }
    cout << sum << endl;
    return 0;
}
