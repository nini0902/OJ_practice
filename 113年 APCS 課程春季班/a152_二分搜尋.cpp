#include <bits/stdc++.h>
using namespace std;
int tf = 1;

void binary_search(vector<int> A, int n, int target){
    int l = 0, r = n-1, mid, cnt = 0;
    while(tf){
        mid = (l+r)/2;
        cnt++;
        if(l > r) {
            cout << "not found " << cnt-1 << endl; //找不到
            tf = 0;
        }
        else if(A[mid] == target) { //剛好找到
            cout << mid << " " << cnt << endl;
            tf = 0;
        }
        else if(A[mid] > target) r = mid-1; //比目標還大(往左找)
        else l = mid+1; //比目標還小(往右找)
    }
}

int main(){
    int n,t, cnt = 0;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    cin >> t;

    int l = 0, r = n-1, mid = 0;

    binary_search(A,n,t);
return 0;
}
