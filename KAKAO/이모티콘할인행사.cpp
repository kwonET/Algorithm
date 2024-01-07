#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> dc={10,20,30,40};
int emlen=0;
vector<int> list;
vector<int> answer={0,0};
vector<vector<int>> glo_users;
vector<int> glo_emoticons;
void dfs(int idx){
    if(idx==emlen){
        int totalcost=0;
        int plus=0;
        for(auto user:glo_users){   
            int cost=0;
            for(int i=0;i<emlen;i++){
                if(user[0]<=list[i]){
                    cost+=glo_emoticons[i]*(100-list[i])*0.01;
                }
            }
            if(cost>=user[1]){
                plus+=1;
            }
            else {
                totalcost+=cost;
            }
        }
        // cout<<plus<<" "<<totalcost<<"\n";
        if(answer[0]<plus){
            answer[0]=plus;
            answer[1]=totalcost;
        }
        if(answer[0]==plus && answer[1]<totalcost){
            answer[1]=totalcost;
        }
        return;
    }
    else{
        for(int i=0;i<4;i++){
            list.push_back(dc[i]);
            dfs(idx+1); //idx가 emlen이 되면 dfs에서 나와 이전 단계인 idx-1을 점차 수행하는 것임
            list.pop_back();
        }
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    emlen=emoticons.size();
    glo_emoticons=emoticons;
    glo_users=users;
    dfs(0);
    
    return answer;
}