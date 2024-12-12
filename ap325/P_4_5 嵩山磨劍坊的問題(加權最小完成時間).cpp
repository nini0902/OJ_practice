#include <bits/stdc++.h>
#define t first
#define w second
using namespace std;

bool comp(pair<double,double>& a, pair<double,double>& b){
    return a.w/a.t > b.w/b.t;
    //單位時間內，權重較大者在前面
}

int main(){
    int n;
    cin >> n;
    vector<pair<double,double>> vec(n);

    for(int i = 0; i < n; i++) cin >> vec[i].t;
    for(int i = 0; i < n; i++) cin >> vec[i].w;

    sort(vec.begin(), vec.end(), comp);

    long long sum = 0, sumt = 0;
    for(int i = 0; i < n; i++){
        sumt += vec[i].t; //完成時間
        sum += sumt * vec[i].w; //完成時間*權重
    }

    cout << sum << endl;

    return 0;
}
