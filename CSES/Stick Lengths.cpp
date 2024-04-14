#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,mid,sum = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.end());

    mid = n/2;

    for(int i = 0; i < n; i++){
        sum += abs(a[i] - a[mid-1]);
    }

    cout << sum << endl;
return 0;  
}
