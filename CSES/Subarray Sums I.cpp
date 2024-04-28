#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
vector<LL> vec;
LL x, n;
LL sum = 0, cnt = 0;

int main(){
    cin >> n >> x;
    vec.assign(n,0);

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    LL f = 0;
    for(int i = 0; i < n; i++){
        sum += vec[i];
        if(sum >= x){
            if(sum == x){
                cnt++;
            }
            while(sum >= x && f != i){
                sum -= vec[f];
                f++;
            }
        }
        if(sum == x && i == n-1) cnt++;
    }

    cout << cnt << endl;
return 0;
}
