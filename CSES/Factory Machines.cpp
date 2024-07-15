#include <bits/stdc++.h>
using namespace std;

long long bin_search(long long n, long long t, vector<long long>& k){
    long long l = 0, r = t*k[n-1], mid = (l+r)/2;
    long long mm = t * k[n-1]; //將mm設成最大的可能值

    while(l < r){
        mid = (l+r)/2;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            /*sum的用意只是要確認mid這個時間製造的量夠不夠t個
              如果確認會大於T，直接設成t+1就可以判斷了，還能避免溢位或多餘的計算*/
            if(sum > t) {sum = t+1;break;} 
            sum += mid/k[i];
        }

        if(sum >= t) mm = min(mm,mid); //如果sum > t，表示mid這個時間製造量是夠的

        //基本的二分搜
        if(sum >= t) r = mid;
        else l = mid+1;
    }
    return mm;
}

int main(){
    long long n,t;
    cin >> n >> t;
    vector<long long> k(n);

    for(int i = 0; i < n; i++) cin >> k[i];
    sort(k.begin(), k.end()); //排序

    cout << bin_search(n,t,k) << endl;
    return 0;
}
