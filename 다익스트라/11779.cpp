#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,from,to,start,fin;
int Next,cur;
int cost, ncost;
vector <pair<int,int>> distarr[1001];
priority_queue <pair<int,int>> pq;
int D[1001]; //start 정점에서 시작해 최단거리를 갱신하는 배열
int visited[1001];
vector <int> path;

void Dijstra(){
    fill_n(D, n, 1e9);
    pq.push({start,0});
    D[start]=0; //시작 정점은 거리가 0
    while(!pq.empty()){
        cur=pq.top().first;
        cost=-pq.top().second;
        pq.pop();
        if(D[fin]<cost){ // 더 이상 최단 경로 갱신이 불가한 경우 -> 시간초과 해결
            continue;
        }
        for(int i=0;i<distarr[cur].size();i++){
            Next=distarr[cur][i].first;
            ncost=distarr[cur][i].second;
            if(D[Next]>ncost+cost){
                D[Next]=ncost+cost;
                pq.push({Next,-D[Next]});
                visited[Next]=cur;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    while(m--){
        cin>>from>>to>>cost;
        distarr[from-1].push_back({to-1,cost});
    }
    cin>>start>>fin;
    start-=1;fin-=1;
    Dijstra();

    cout<<D[fin]<<endl;
    int t=fin;
    while(true){
        path.push_back(t);
        if(t==start){
            break;
        }
        t=visited[t];
    }
    cout<<path.size()<<"\n";
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i]+1<<" ";
    }
    return 0;
}