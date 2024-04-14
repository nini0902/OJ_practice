#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,cnt = 1;
    string s;
    cin >> n;
    vector<int> c(5);
    vector<long long> C(n);
    vector<int> stu;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            cin >> c[j];
        }
        sort(c.begin(),c.end());
        s = to_string(c[0])+to_string(c[1])+to_string(c[2])+to_string(c[3])+to_string(c[4]); //把課程按照順序排列成一組新的數字
        C[i] = stoll(s);
        s.clear();
        c.assign(5,0);
    }

    sort(C.begin(),C.end());
    
    for(int i = 1; i < n; i++){
        if(C[i] != C[i-1]){
            stu.push_back(cnt);
            cnt = 1;
        }
        else cnt++;
    }
    stu.push_back(cnt);

    sort(stu.begin(),stu.end());
    reverse(stu.begin(), stu.end());
    cnt = stu[0];
    
    for(int i = 1; i < stu.size(); i++){
        if(stu[i] == stu[i-1]) cnt += stu[i];
        else break;
    }

    cout << cnt << endl;
return 0;
}
