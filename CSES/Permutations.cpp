#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    
    long long cnt = 0;
    for(int i = 1; i < n; i++){
      if(vec[i] < vec[i-1]){
        cnt += (vec[i-1] - vec[i]);
        vec[i] = vec[i-1];
      }
    }
    cout << cnt << endl;
    return 0;
}
