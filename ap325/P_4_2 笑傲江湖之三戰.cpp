#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, win = 0;
    cin >> n;
    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0, inb = 0; i < n && inb < n; i++){
        if(a[i] > b[inb]) {win++; inb++;}
    }

    cout << win << endl;
    return 0;
}
