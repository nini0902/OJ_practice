#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a > b;
}
int main(){
    int N,cnt = 0;
    cin >> N;
    vector<int> v(N+1);
    for(int i = 1; i <= N; i++) cin >> v[i];

    sort(v.begin()+1,v.end(),comp);

    for(int i = 1; i <= N; i++){
        if(i%3 != 0) cnt += v[i];
    }
    cout << cnt << endl;
return 0;
}
