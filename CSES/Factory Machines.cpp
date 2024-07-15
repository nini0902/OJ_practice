#include <bits/stdc++.h>
using namespace std;

long long bin_search(long long n, long long t, vector<long long>& k){
    long long l = 0, r = t*k[0], mid = (l+r)/2, mm = LLONG_MAX;

    while(l < r){
        mid = (l+r)/2;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += mid/k[i];
        }

        if(sum >= t) mm = min(mm,mid);

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
    sort(k.begin(), k.end());

    cout << bin_search(n,t,k) << endl;
    return 0;
}
