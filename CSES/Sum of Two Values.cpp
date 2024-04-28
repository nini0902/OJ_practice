#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,yn = 0,t = 1;
    long long x;
    cin >> n >> x;
    vector<long long> vec(n+1);
    int l = 1, r = n;

    for(int i = 1; i <= n; i++){
        cin >> vec[i];
    }

    int m = r;
    for(int i = 1; i < n; i++){
        if(l >= m) break;
        l = i, r = m;
        while(t){
            if(vec[l] + vec[r] == x){
                cout << l << " " << r << " ";
                m = r-1, yn = 1;
                t = 0;
            }
            else{
                r--;
                if(r <= l) t = 0;
            }
        }
        t = 1;
    }

    if(!yn) cout << "IMPOSSIBLE";
    cout << endl;
return 0;
}
