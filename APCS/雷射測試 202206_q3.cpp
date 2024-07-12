/*
解題思路：
因為光線只能橫著或直著走(表示尋找的目標鏡子x值和y值一定有一個和目前的點一樣)
所以只要先找到那個固定的x或y值(例如向右就是y固定，去找比目前更大的x就是答案)
如果找不到固定，表示這個光線前面已經沒有鏡子了，break出來就好了

哦對，至於那個dir的變動方式，畫圖應該就知道了
例如向右的光碰到/(0)，方向就變成向上；碰到\(1)，方向就是向下
  */
#include <bits/stdc++.h>
using namespace std;

//專門用來排y值用的
bool com(const pair<int,int>& a, const pair<int,int>& b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    int n, dir = 1, nx = 0, ny = 0, cnt = 0; 
    cin >> n;
    vector<pair<int,int>> mx(n); //儲存用x值排的順序
    vector<pair<int,int>> my(n); //儲存用y值排的順序
    map<pair<int,int>, int> mi; //查找鏡子方向

    for(int i = 0,a; i < n; i++) {
        cin >> mx[i].first >> mx[i].second;
        my[i] = mx[i];
        cin >> a;
        mi[{mx[i].first, mx[i].second}] = a;
    }
    sort(mx.begin(), mx.end()); //用x值排
    sort(my.begin(), my.end(), com); //用y值排

    while(1){
        if(dir == 1){ //方向向右
            //先找相同的y
            auto it = lower_bound(my.begin(), my.end(), make_pair(nx,ny), com);
            if(it->second != ny) break; 
            //找到比目標更大的x值，條件是保障不超出範圍，且x要大於現在的x值
            while(it != my.end() && (it->first <= nx && it->second == ny)) ++it; 
            if(it->second != ny) break; 
            nx = it->first, ny = it->second;
            if(mi[make_pair(nx,ny)] == 0) dir = 4;
            else dir = 2;
            cnt++;
        }
        else if(dir == 2){ //方向向下
            auto it = lower_bound(mx.begin(), mx.end(), make_pair(nx,ny));
            if(it->first != nx) break;
            //找到比目標更小的y值，條件是保障不超出範圍，且y要小於現在的值
            while(it != mx.begin() && (it->second >= ny && it->first == nx)) --it;
            if(it->first != nx) break;
            nx = it->first, ny = it->second;
            if(mi[make_pair(nx,ny)] == 0) dir = 3;
            else dir = 1;
            cnt++;
        }
        else if(dir == 3){ //方向向左
            auto it = lower_bound(my.begin(), my.end(), make_pair(nx,ny), com);
            if(it->second != ny) break;
            while(it != my.begin() && (it->first >= nx && it->second == ny)) --it;
            if(it->second != ny) break;
            nx = it->first, ny = it->second;
            if(mi[make_pair(nx,ny)] == 0) dir = 2;
            else dir = 4;
            cnt++;
        }
        else if(dir == 4){ //方向向上
            auto it = lower_bound(mx.begin(), mx.end(), make_pair(nx,ny));
            if(it->first != nx) break;
            while(it != mx.end() && (it->second <= ny && it->first == nx)) ++it;
            if(it->first != nx) break;
            nx = it->first, ny = it->second;
            if(mi[make_pair(nx,ny)] == 0) dir = 1;
            else dir = 3;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
