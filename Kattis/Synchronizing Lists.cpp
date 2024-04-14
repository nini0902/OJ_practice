#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> s1;
    vector<int> s2;
    vector<int> s3;
    while(cin >> n && n != 0){
        s1.assign(n,0); // 初始化vector
        s2.assign(n,0);
        s3.assign(n,0);
        for(int i = 0; i < n; i++){
            cin >> s1[i];
            s2[i] = s1[i]; //s1為原本排序 s2會拿去sort
        }

        for(int i = 0; i < n; i++) cin >> s3[i];

        sort(s2.begin(), s2.end());
        sort(s3.begin(), s3.end());

        for(int i = 0; i < n; i++){
            auto it = find(s2.begin(), s2.end(), s1[i]);
            int d = distance(s2.begin(),it); //找到s1該數sort以後的位置
            cout << s3[d] << endl;
        }
        cout << endl;
    }
return 0;
}
