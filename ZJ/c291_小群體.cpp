#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class person{
    public:
    int bff;

    void add_bff(int f){
        bff = f;
    }
}

;int find_new(vector<person>& p){
    for(int i = 0; i < p.size(); i++){
        if(p[i].bff!=-1){
            return i;
        }
    }
return -1;
}

;int cnt_g(vector<person>& p){
    int p1,temp;
    p1 = find_new(p);
    if(p1==-1){
        return 0;
    }
    while(p[p1].bff != -1){
        temp = p[p1].bff;
        p[p1].bff = -1;
        p1 = temp;
    }
    int count = cnt_g(p)+1;
    return count;
}

;int main(){
    int fp,sp,tt,count;
    cin >> tt;
    vector<person> people(tt);
    for(int i = 0; i < people.size(); i++){
        cin >> sp;
        people[i].add_bff(sp);
    }
    
    count = cnt_g(people);
    cout << count << endl;
return 0;
}
