#include <bits/stdc++.h>
using namespace std;

int bin_search(int n, int t, vector<int>& k){
    int l = 0, r = t*k[0], mid = (l+r)/2;

    while(l < r){
        mid = (l+r)/2;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += mid/k[i];
        }
        if(sum >= t) r = mid;
        else l = mid+1;
    }
    return mid;
}

int main(){
    int n,t;
    cin >> n >> t;
    vector<int> k(n);

    for(int i = 0; i < n; i++) cin >> k[i];
    sort(k.begin(), k.end());

    cout << bin_search(n,t,k) << endl;
    return 0;
}
