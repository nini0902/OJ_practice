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

    for(int i = 0; i < n; i++){
        sum += vec[i];
        cnt++;
        if(sum == x) break;
        else if(sum > x){
            sum = 0;
            cnt = 0;
        }
    }

    cout << cnt << endl;
return 0;
}
