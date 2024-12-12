#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    long long sum = 0, ans = 0, ans1 = 0;
    cin >> n >> k;
    queue<long long> q;

    for(int i = 0,num; i < n; i++){
        cin >> num;
        
        sum += num; //sum先加上新的數字
        q.push(num); //push進去

        while(sum > k){ //如果sum會炸掉就進入迴圈
            sum -= q.front(); //扣掉目前區間的頭
            q.pop(); //pop掉區間的頭
        }
        
        if(sum > ans) {ans = sum; ans1 = 1;} //出現更大的sum，ans1要重置
        else if(sum == ans) ans1++; //重複出現最大sum，ans+1
    }

    cout << ans << endl; //最大區間和
    cout << ans1 << endl; //區間數量
    return 0;
}
