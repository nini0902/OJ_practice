#include <bits/stdc++.h>
#define s first
#define e second
using namespace std;

bool comp(pair<int,int>& a, pair<int,int>& b){
    return a.e < b.e;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i].s >> vec[i].e;

    sort(vec.begin(), vec.end(), comp);

    int cnt = 1, end = vec[0].e; //第一場已經設好了
    for(int i = 1; i < n; i++){
        if(vec[i].s > end){ //開始時間大於上一場結束時間
            cnt++;
            end = vec[i].e; //更新結束時間
        }
    }

    cout << cnt << endl;
    return 0;
}
