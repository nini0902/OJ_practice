//二分搜
#include <bits/stdc++.h>
using namespace std;

int find_r(int n, int k, vector<int>& vec){
    int l = 0, r = vec.back() - vec.front();

    while(l < r){
        int mid = l + (r-l) /2;
        int cnt = 1, last_cov = vec[0] + mid;
        for(int i = 1; i < n; i++){
            if(vec[i] > last_cov){
                cnt++;
                last_cov = vec[i]+mid;
            }
        }
        if(cnt <= k) r = mid;
        else l = mid+1;
    }
    if(l == 0) return 1;
    else return l;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    map<int,bool> m;
    for(int i = 0,a; i < n; i++) {
        cin >> a;
        if(m[a] == 0) {vec.push_back(a);m[a] = true;}
    }
    sort(vec.begin(), vec.end());

    cout << find_r(n,k,vec) << endl;
    return 0;
}
