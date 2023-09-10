#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> v; //1차원 벡터
vector<pair<int,int>> v2[1002]; //from,to의 pair값을 갖는 1002개의 cost값을 표현


int main(){
    priority_queue<pair<int,int>> pq; //pair을 가지는 우선순위 큐, 첫번째 값으로 내림차순 정렬
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        int cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        for(int i=0;i<v2[1002].size();i++){
            printf("something");
        }
    }
    return 0;
}