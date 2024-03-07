#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int unlucky = -1, lucky = 101;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] < 60 && a[i] > unlucky) unlucky = a[i];
        else if (a[i] >= 60 && a[i] < lucky) lucky = a[i];
    }
    sort(a.begin(), a.end());

    for(int i = 0; i < n-1; i++) cout << a[i] << " ";
    cout << a[n-1] << endl;

    if(unlucky == -1) cout << "best case" << endl;
    else cout << unlucky << endl;
    if(lucky == 101) cout << "worst case" << endl;
    else cout << lucky << endl;
return 0;
}
