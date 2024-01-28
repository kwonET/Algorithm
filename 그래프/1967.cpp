#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
// 어떤 두 노드를 선택해서 양쪽으로 쫙 당길 때, 
// 가장 길게 늘어나는 경우가 있을 것이다. 
// 이럴 때 트리의 모든 노드들은 이 두 노드를 지름의 끝 점으로 하는 원 안에 들어가게 된다.
// 이런 두 노드 사이의 경로의 길이를 트리의 지름이라고 한다. 
// 정확히 정의하자면 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이를 말한다.
// 즉, 2개의 정점 사이 가중치의 합 중에 가장 큰 경우

// 인접리스트로 관리
//한 정점에서 다른 정점으로 가는 dfs 형태 -> 최댓값을 갱신
//갈 수 있는 노드를 간다 -> 되돌아오면서 가중치를 더한다
//노드*간선 100,000,000개
int n,a,b,c,result;
stack <pair<int,int>> st;
vector <pair<int,int>> path[10001];
int visited[10001];
int dfs(int idx,int c){
    st.push({idx,c});
    visited[idx]=1;
    int maxC=0;
    while(!st.empty()){
        int cur=st.top().first;
        int cost=st.top().second;
        if(maxC<cost){maxC=cost;}
        st.pop();
        for(int i=0;i<path[cur].size();i++){
            int next=path[cur][i].first;
            int ncost=path[cur][i].second;
            if(visited[next]==1)continue;
            st.push({next,ncost+cost});
            visited[next]=1;
        }
    }
    return maxC;
}
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        path[a].push_back({b,c});
        path[b].push_back({a,c});
    }
    for(int j=1;j<=n;j++){
        memset(visited,0,sizeof(visited));
        int answer=dfs(j,0);
        if(result<answer){
            result=answer;
        }
    }
    cout<<result;
    return 0;
}