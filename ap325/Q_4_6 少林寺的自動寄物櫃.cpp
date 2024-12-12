#include <bits/stdc++.h>
#define w first
#define f second
using namespace std;

bool comp(pair<int,int>& a, pair<int,int>& b){
    return b.w*a.f > a.w*b.f;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i].w;
    for(int i = 0; i < n; i++) cin >> vec[i].f;

    sort(vec.begin(), vec.end(), comp);

    long long sum = 0, s = 0;
    for(int i = 0; i < n; i++){
        sum += s*vec[i].f;
        s += vec[i].w; //第 i 個的重量要 i+1 才會消耗
    }

    cout << sum << endl;
    return 0;
}
