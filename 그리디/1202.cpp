// deque로 끝값을 빼는 대신, pq로 계속해서 순서를 유지해서 이진탐색으로 해당값을 pop할 수 있는 방법이 있다.
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;
int jw,bag,i,a,b,c;

vector<pair<int,int>> jwInfo; //보석의 무게, 보석의 가격
vector<int> bagInfo; //가방의 무게
priority_queue<int> pq;
struct compare{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        return (a.second<b.second); // * 순서 확인하기
    }
};
int main(){
    cin>>jw>>bag;
    for(i=0;i<jw;i++){
        cin>>a>>b;
        jwInfo.push_back({a,b});
    }
    for(i=0;i<bag;i++){
        cin>>c;
        bagInfo.push_back(c);
    }
    sort(jwInfo.begin(),jwInfo.end()); //왜 compare 빼도 맞는건지? -> 첫번째 인자에 따라서 정렬 (무게)
    sort(bagInfo.begin(),bagInfo.end());
    
    int idx=0;
    long long totaljw=0;
    for(auto bags:bagInfo){
        while(idx<jw && bags>=jwInfo[idx].first){
            pq.push(jwInfo[idx].second);
            idx++;
        } 
        if(!pq.empty()){ //맨 위에 있는 최댓값에 대해 한번만 실행
            totaljw+=pq.top();
            pq.pop();
        }
    }
    cout<<totaljw<<endl;
    return 0;
}