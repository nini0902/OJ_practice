#include <bits/stdc++.h>
using namespace std;

int count_song(int song, vector<unsigned int>& s){
    //在排序過的資料哩，找某個元素出現的頭跟尾
    auto l = lower_bound(s.begin(),s.end(), song);
    auto u = upper_bound(s.begin(), s.end(), song);
    return u-l;
}

int main(){
    int n, q, a;
    cin >> n;
    vector<unsigned int> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(),s.end());

    cin >> q;
    while(q--){
        cin >> a;
        cout << count_song(a,s) << endl;
    }
    return 0;
}
