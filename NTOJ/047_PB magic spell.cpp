//二分搜(upper_bound, lower_bound)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    cin >> t;
    for(int i = 0,a,b,k; i < t; i++){
        cin >> k;
        auto it = lower_bound(vec.begin(), vec.end(), k);

        if(it != vec.end() && *it == k) cout << k << endl;
        else{
            //it返回vec.end()時，*it是未定義的(因為it超出容器範圍)
            if(it == vec.begin()) cout << "no " << *it << endl;
            else if(it == vec.end()) cout << vec.back() << " no" << endl;
            else cout << *prev(it) << " " << *it << endl;
        }
    }
    return 0;
}
