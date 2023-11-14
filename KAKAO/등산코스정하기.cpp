
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<pair<int,int>> pq;
vector <pair<int, int>> p[50001];
int dist[50001];
int summit[50001];
int i;

void dijkstra(vector<int> &gates){   
    int i,inten,cur,to,weight;
    for(auto g: gates){
        pq.push({0,g});
        dist[g]=0;
    }
    while(!pq.empty()){
        inten=-pq.top().first; //현재까지 저장한 최대 intensity
        cur=pq.top().second; //현재 위치
        pq.pop();
        if(inten>dist[cur] || summit[cur]){continue;}
        for(auto v:p[cur]){
            to=v.first; //다음 위치
            weight=v.second; //다음 위치로의 거리
            
            if(dist[to]>max(inten,weight)){
                dist[to]=max(inten,weight);
                pq.push({-dist[to],to});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    for(auto s:summits){
        summit[s]=1;
    }
    
    for(auto line:paths){
        int a=line[0]; int b=line[1]; int c=line[2];
        p[a].push_back({b,c});
        p[b].push_back({a,c});
    }
    
    for(i=1;i<=n;i++){
        dist[i]=1e9;
    }

    sort(gates.begin(),gates.end());
    sort(summits.begin(), summits.end());
    dijkstra(gates);  
    
    int minDist=1e9;
    int maxS;
    for(auto cand:summits){
        if(minDist>dist[cand]){
            minDist=dist[cand];
            maxS=cand;
        }
    }
    answer.push_back(maxS);
    answer.push_back(minDist);
    
    return answer;
}