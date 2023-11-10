#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <deque>
using namespace std;
long long sum1,sum2;
int i,target,flag;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    deque<int> dq1;
    deque<int> dq2;
    for(i=0;i<queue1.size();i++){
        sum1+=queue1[i];
        dq1.push_back(queue1[i]);
    }
    for(i=0;i<queue2.size();i++){
        sum2+=queue2[i];
        dq2.push_back(queue2[i]);
    }
    if((sum1+sum2)%2!=0){
        answer=-1;
        return answer;
    }
    
    while(sum1!=sum2){
        if(answer>299999){
            answer=-1;
            return answer;
        }
        // if(answer>0&&queue1==org1){
        //     answer=-1;
        //     return answer;
        // }
        if(sum1<sum2){
            target=dq2.front();
            dq1.push_back(target);
            dq2.pop_front();
            sum2-=target;
            sum1+=target;
        }
        else if(sum1>sum2){
            target=dq1.front();
            dq2.push_back(target);
            dq1.pop_front();
            
            // queue1.erase(queue1.begin());
            // queue2.push_back(target);
            sum1-=target;
            sum2+=target;
        }
        answer+=1;
    }
    
    return answer;
}