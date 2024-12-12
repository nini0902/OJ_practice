#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());

    long long tt = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += vec[i]; //第0筆加到第i筆的總和(前綴和)
        tt += sum; //加上這次的總和
    }
    cout << tt << endl;
    return 0;
}
