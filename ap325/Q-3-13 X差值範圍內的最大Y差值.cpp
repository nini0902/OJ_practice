#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int main(){
    int n,l;
    long long ans = 0,M;
    cin >> n >> l;
    vector<pair<int,int>> vec(n);
    queue<int> max_q, min_q;

    for(int i = 0; i < n; i++) cin >> vec[i].x;
    for(int i = 0; i < n; i++) cin >> vec[i].y;

    sort(vec.begin(), vec.end()); //x排序

    for(int i = 0; i < n; i++){
        int nx = vec[i].x, ny = vec[i].y;
        max_q.push(i);
        min_q.push(i);

        while(!max_q.empty() && nx-vec[max_q.front()].x>l || vec[max_q.front()].y < ny){
            //超出範圍或無用資料
            max_q.pop();
        }

        while(!min_q.empty() && nx-vec[min_q.front()].x>l || vec[min_q.front()].y > ny){
            min_q.pop();
        }

        M = vec[max_q.front()].y - vec[min_q.front()].y;
        ans = max(ans, M);
    }

    cout << ans << endl;

    return 0;
}
