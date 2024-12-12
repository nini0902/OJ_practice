#include <bits/stdc++.h>
using namespace std;
#define N 100010

int d(int n, int f[], int t[]){
    if(n < 1) return 0;
    vector<int> v(f,f+n);
    sort(v.begin(), v.end());
    t[0] = v[0];
    int num = 1;
    for(int i = 1; i < n; i++){
        if(v[i]!=v[i-1]) t[num++] = v[i];
    }
    return num;
}

int main(){
    int n, a[N],b[N],k;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    k = d(n,a,b);
    for(int i = 0; i < n; i++) a[i] = lower_bound(b,b+k,a[i])-b;
    for(int i = 0; i < n; i++) cout << a[i] << " ";
return 0;
}
