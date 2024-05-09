#include <bits/stdc++.h>
using namespace std;
vector<int> ans;

void check(string s){
    string rs = s;
    reverse(rs.begin(), rs.end()); //確認反轉後是否相同
    if(rs == s) ans.push_back(stoi(s)); //轉成整數儲存
    return;
}

bool isLeap(int year){ //判斷閏年
    if((year%4==0 && year%100 != 0) || year%400==0){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        ans.clear();
        int y;
        cin >> y;
        int md[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        md[2] += (isLeap(y)?1:0); //閏年的2月多一天
        for(int i = 1; i <= 12; i++){
            for(int j = 1; j <= md[i]; j++){
                //不做任何動作
                check(to_string(y) + to_string(i) + to_string(j));
                //月份補0
                if(i < 10) check(to_string(y) + "0" + to_string(i) + to_string(j));
                //日期補0
                if(j < 10) check(to_string(y) + to_string(i) + "0" + to_string(j));
                //月份及日期都補0
                if(i < 10 && j < 10) check(to_string(y) + "0" + to_string(i) + "0" + to_string(j));
            }
        }
        sort(ans.begin(),ans.end()); //排序
        cout << ans.size() << " ";
        for(auto i : ans) cout << i << " ";
        cout << endl;
    }
return 0;
}
