#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class person{
    public:
    int parent;
    int height;
    int total_height;
    vector<int> children;
    vector<int> ch_height;

    void p(int p1){
        parent = p1;
    }
    void h(int h1){
        height = h1;
    }
    void ch(int ch1){
        children.push_back(ch1);
    }
    void ch_h(int ch1){
        ch_height.push_back(ch1);
    }
    void tth(int tth1){
        total_height = tth1;
    }
    person() : parent(-1), height(-1), children(1,-1){
        ch_height.clear();
    }
}

;bool bs(int a, int b){
    return a> b;
}
;int find_top(vector<person> &people){
    for(int i = 0; i < people.size(); i++){
        if(people[i].parent==-1){
            return i;
        }
    }
    return 0;
}

int find_len(vector<person>& people, int p){
    int max1 = 0;
    for(int i : people[p].children){
        int len = find_len(people,i)+1;
        max1 = max(max1,len);
        people[p].height = max1;
    }
    return max1;
}

int find_top1(vector<person>& people){
    for(int i = 0; i < people.size(); i++){
        if(people[i].children.size() > 2){
            return i;
        }
    }
    return 0;
}

void def_height(vector<person>& people){
    int temp, t = 0, sum;
    for(int i = 0; i < people.size();i++){
        people[i].ch_h(-1);
        for(int j = 1; j < people[i].children.size(); j++){
            temp = people[i].children[j];
            people[i].ch_h(people[temp].height);
            t = j;
        }
        sort(people[i].ch_height.begin(), people[i].ch_height.end(),bs);
    }
}

void tt_height(vector<person>& people){
    int sum;
    for(int i = 0; i < people.size(); i++){
        if((people[i].ch_height[1]==-1)||(people[i].ch_height[0]==-1)){
            people[i].tth(0);
        }
        else{
            sum = people[i].ch_height[0]+people[i].ch_height[1];
            people[i].tth(sum);
        }
    }
}

int find_max(vector<person>& people){
    int max = 0;
    for(int i = 0; i < people.size(); i++){
        if(people[i].total_height>max){
            max = people[i].total_height;
        }
    }
    return max;
}

;int main(){
    int total_mem,p,ch,top,top1,max;
    cin >> total_mem;
    vector<person> people(total_mem);
    while(cin >> p >> ch){
        people[p].ch(ch);
        people[ch].p(p);
    }
    top = find_top(people);
    people[top].height = find_len(people,top);
    top1 = find_top1(people);
    def_height(people);
    tt_height(people);
    max = find_max(people);

    cout << max << endl;
return 0;
}
