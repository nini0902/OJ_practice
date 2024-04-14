#include <bits/stdc++.h>
using namespace std;

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

int main(){
    int P,num,cnt,k;
    vector<int> K;
    cin >> P;
    while(P--){
        cnt = 0; // 將 cnt 重置為 0
        cin >> k;
        // 將資料先輸入
        for(int i = 0; i < 20; i++){
            cin >> num;
            K.push_back(num);
        }
        
        // 插入排序
        for(int i = 1; i < 20; i++){
            for(int j = i; j > 0 && K[j] < K[j-1]; j--){
                swap(K[j],K[j-1]);
                cnt++;
            }
        }

        cout << k << " " << cnt << endl;
        K.clear();
    }
    return 0;
}
