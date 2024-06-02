#include <bits/stdc++.h>
using namespace std;
map<int, queue<string>> mp;

int main(){
    char x;
    for(int i = 0; i < 4; i++){
        cin >> x;
        for(int j = 0; j < 13; j++){
            string s;
            cin >> s;
            mp[x-'A'].push(s); //A->0 B->1 C->2 D->3
        }
    }
    int id = 0; //出排玩家
    int dir = 1; //進行方向
    int sum = 0; //數字總和

    while(sum <= 99){
        string card = mp[id].front(); //出掉第一張牌
        mp[id].pop();
        //根據遊戲規則進行判斷
        if(card=="A") sum = 0;
        else if(card=="4") dir*=-1;
        else if(card=="5") ;
        else if(card=="10"){
            sum += 10;
            if(sum>99) sum -= 20;
        }
        else if(card=="J") ;
        else if(card=="Q"){
            sum += 20;
            if(sum > 99) sum -= 40;
        }
        else if(card=="K") sum = 99;
        else{ //其他數字牌
            sum += card[0]-'0';
            if(sum > 99){ //輸了：超過99
                cout << char('A'+id) << endl;
                cout << mp[id].size() << endl;
                break;
            }
            if(mp[id].empty()){ //贏了：手上沒牌
                cout << char('A'+id) << endl;
                cout << sum << endl;
                break;
            }
        }
        id = (id + dir + 4)%4; //保證他不會超出去(簡略寫法)
    }
return 0;
}
