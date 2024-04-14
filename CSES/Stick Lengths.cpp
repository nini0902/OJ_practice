#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,mid,sum = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.end());

    mid = n/2;
    cout << a[mid] << endl;
    for(int i = 0; i < n; i++){
        sum += abs(a[i] - a[mid]);
    }

    cout << sum << endl;
return 0;  
}
