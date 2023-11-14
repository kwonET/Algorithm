
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
    for(i=0;i<gates.size();i++){
        pq.push({0,gates[i]});
        dist[gates[i]]=0;
    }
    while(!pq.empty()){
        inten=-pq.top().first; //현재까지 저장한 최대 intensity
        cur=pq.top().second; //현재 위치
        pq.pop();
        if(inten>dist[cur] || summit[cur]){continue;}
        for(i=0;i<p[cur].size();i++){
            to=p[cur][i].first; //다음 위치
            weight=p[cur][i].second; //다음 위치로의 거리
            
            if(dist[to]>max(inten,weight)){
                dist[to]=max(inten,weight);
                pq.push({-dist[to],to});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    for(i=0;i<summits.size();i++){
        summit[summits[i]]=1;
    }
    
    for(i=0;i<paths.size();i++){
        int a=paths[i][0]; int b=paths[i][1]; int c=paths[i][2];
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
    for(i=0;i<summits.size();i++){
        if(minDist>dist[summits[i]]){
            minDist=dist[summits[i]];
            maxS=summits[i];
        }
    }
    answer.push_back(maxS);
    answer.push_back(minDist);
    
    return answer;
}