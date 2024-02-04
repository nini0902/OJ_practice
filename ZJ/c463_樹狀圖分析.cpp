#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_len(vector<vector<int>>& f, int r, long long& count) { 
    if (f[r][0] == 0) {
        return 0;
    }
    int m1 = -1, l;
    l = f[r][0];
    for (int j = 1; j <= l; j++) {
        int len = find_len(f, f[r][j], count) + 1; 
        m1 = max(m1, len);
    }
    count += m1; 
    return m1;
}

int main() {
    int n, a, r, h,temp;
    long long count = 0;
    cin >> n;
    vector<int> as(n + 1, 0);
    vector<vector<int>> f(n+1,vector<int>(1,0));
    for (int i = 1; i <= n; i++) {  
        cin >> a;
        for (int j = 1; j <= a; j++) {
            cin >> temp;
            f[i].push_back(temp);
            as[f[i][j]] = 1;
        }
        f[i][0] = a; 
    }
    for (int i = 0; i < n; i++) { 
        if (as[i] != 1) {
            r = i;
        }
    }
    cout << r << endl;
    h = find_len(f, r, count);
    cout << count << endl; 
    
    return 0;
}
