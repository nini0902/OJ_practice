#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,l;
    int ans = 0, M = 0;
    cin >> n >> l;
    queue<long long> min_q, max_q;

    for(int i = 0,num; i < n; i++){
        cin >> num;
        max_q.push(num);
        min_q.push(num);

        while(!max_q.empty() && num > max_q.front() || max_q.size() > l){
            //num比front還大或是queue長度大於
            max_q.pop();
        }

        while(!max_q.empty() && num < min_q.front() || min_q.size() > l){
            //num比front還小或是queue長度超過
            min_q.pop();
        }

        M = max_q.front() - min_q.front(); //區段差
        ans = max(M, ans);
    }
    cout << ans << endl;
    return 0;
}
