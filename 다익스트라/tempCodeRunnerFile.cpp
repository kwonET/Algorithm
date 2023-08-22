#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 99999999
using namespace std;
int n,m,x,i,j,a,b,c;
int dist[2][1002];
vector<pair<int, int>> p[2][1002];//방향 그래프

void Dijstra(int k){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,x));
    dist[k][x]=0;
    while(!pq.empty()){
        int cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        // if(cost>dist[k][cur]) continue;
        for(i=0;i<p[k][cur].size();i++){
            int nCur=p[k][cur][i].first;
            int nCost=p[k][cur][i].second+cost;
            if(nCost<dist[k][nCur]){
                pq.push({-nCost,nCur});
                dist[k][nCur]=nCost;
            }
        }
    }
}

int main(){
    scanf("%d %d %d",&n,&m,&x); 
    for(i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        p[0][a].push_back(make_pair(b,c)); //from인덱스에 {to, cost}저장
        p[1][b].push_back(make_pair(a,c)); 
    }

    for(i=0;i<=n;i++)dist[0][i]=INF;
    for(i=0;i<=n;i++)dist[1][i]=INF;
    Dijstra(0);
    Dijstra(1);
    for(i=1;i<=n;i++) printf("%d",dist[0][i]);
    for(i=1;i<=n;i++) printf("%d",dist[1][i]);

    int maxD=0;
    for(i=1;i<=n;i++) maxD=max(maxD,dist[0][i]+dist[1][i]);
    printf("%d",maxD);

    return 0;
}