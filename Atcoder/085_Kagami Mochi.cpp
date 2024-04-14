#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> d(N);
    for(int i = 0; i < N; i++) cin >> d[i]; //輸入數據

    sort(d.begin(),d.end()); //排序(方便待會去掉重複數據)

    int now = d[0], cnt = 1;
    for(int i = 1; i < N; i++){
        if(d[i] != now){ //與上一個數字不同(表示新的一層)
            cnt++;
            now = d[i];
        } 
    }
    cout << cnt << endl;
    return 0;
}
