#include <bits/stdc++.h>
using namespace std;
#define N 100010

int d(int f[], int t[], int n){
    if(n < 1) return 0;
    vector<int> v(f,f+n);
    sort(v.begin(), v.end());
    t[0] = v[0];
    int num = 1;
    for(int i = 1; i < n; i++) if(v[i] != v[i-1]) t[num++] = v[i];
    return num;
}

int main(){
    int n, k;
    int a[N], b[N];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    k = d(a,b,n);
    cout << k << endl;
    for(int i = 0; i < k-1; i++) cout << b[i] << " ";
    cout << b[k-1] << endl;
return 0;
}
