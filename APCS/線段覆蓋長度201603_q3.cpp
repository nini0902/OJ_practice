#include <bits/stdc++.h>
using namespace std;

int main(){
    int start, end, n,cnt = 0;
    cin >> n;
    vector<pair<int,int>> vec(n);

    for(int i = 0; i < n; i++){
        cin >> vec[i].first >> vec[i].second; 
    }
    sort(vec.begin(), vec.end());

    start = vec[0].first, end = vec[0].second;
    for(int i = 1; i < n; i++){
        if(vec[i].first > end) {
            cnt += (end-start);
            start = vec[i].first;
            end = vec[i].second;
        }
        else if(vec[i].second > end) {
            end = vec[i].second;
        }
    }
    cnt += (end - start);
    cout << cnt << endl;
    return 0;
}
