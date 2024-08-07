#include <bits/stdc++.h>
using namespace std;
vector<long long> vec, pre,v;


bool comp(int a,int b){
    if(vec[a] > vec[b]) return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    vec.resize(n+1), pre.resize(n+1), v.resize(n+1);

    for(int i = 1; i <= n; i++){
        cin >> vec[i];
        pre[i] = pre[i-1] + vec[i];
        v[i] = i;
    }

    sort(v.begin(), v.end(), comp); //將索引按照大小排列

    int l = 1, r = n;
    long long ttl,ttr;
    while(l != r){
        while(v.back() > r || v.back() < l){
            v.pop_back(); //剔除不在範圍內的元素
        }
        int index = v.back(); //範圍內以按照順序排列，因此back為範圍內最小值
        v.pop_back();

        ttl = pre[index-1] - pre[l-1]; //計算index左側的總和
        ttr = pre[r] - pre[index]; //計算index右側的總和

        if(ttl > ttr) r = index-1;
        else l = index+1;
    }
    cout << vec[l] << endl;
    return 0;
}
