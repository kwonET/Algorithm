#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define INF 2100000000
using namespace std;
int tc,n,m,t,s,g,h,a,b,d,x;
priority_queue <pair<int,int>> pq;

int D[3][2001];

void Dijstra(vector <pair<int,int>> dist[],int type,int s){
    pq.push({s,0});
    D[type][s]=0; 
    while(!pq.empty()){
        int cur=pq.top().first;
        int cost=-pq.top().second;
        pq.pop(); 
        for(int i=0;i<dist[cur].size();i++){
            int Next=dist[cur][i].first;
            int ncost=dist[cur][i].second;
            if(D[type][Next]>ncost+cost){
                D[type][Next]=ncost+cost;
                pq.push({Next,-D[type][Next]});
            }
        }
    }
}
int main(){
    cin>>tc;
    while(tc--){
        vector <pair<int,int>> dist[2001];
        vector <int> result;
        vector <int> finlist;

        // fill_n(D,n+2,INF);
        fill(&D[0][0], &D[2][2001], INF);

        cin>>n>>m>>t;
        cin>>s>>g>>h;
        while(m--){
            cin>>a>>b>>d;
            dist[a].push_back({b,d});
            dist[b].push_back({a,d});
        }
        while(t--){
            cin>>x;
            finlist.push_back(x);
        }

        Dijstra(dist,0,s);
        Dijstra(dist,1,g);
        Dijstra(dist,2,h);
        // for(int j=0;j<3;j++){
        //     for(int i=0;i<n;i++){
        //         cout<<D[j][i]<<" ";
        //     }cout<<endl;
        // }cout<<"\n";
        for(auto way:finlist){
            // cout<<"\n" <<way<<" "<<D[0][way]<<"\n";
            if((D[0][g]+D[1][h]+D[2][way]==D[0][way])||(D[0][h]+D[2][g]+D[1][way]==D[0][way])){
                result.push_back(way);
            }
        }
        
        sort(result.begin(),result.end());
        for(auto r:result){
            cout<<r<<" ";
        }cout<<"\n";
    }
    
    return 0;
}