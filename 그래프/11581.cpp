#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
// 첫 번째 줄에 교차로의 수 N(1 ≤ N ≤ 100)이 주어진다. 
// 그다음에 1번 교차로부터 N-1번 교차로의 상태가 각각 두 줄에 걸쳐 차례대로 주어진다. 
// (1 ≤ i ≤ N-1)번째 교차로와 연결된 교차로의 수 Mi(0 ≤ Mi ≤ N)가 주어지고 
// 그다음 줄에는 i번째에서 갈 수 있는 교차로의 번호 Ci(1 ≤ Ci ≤ N)가 주어진다. 
// N번 교차로는 대피소가 있는 곳이기 때문에 연결 상태가 주어지지 않는다. 
// 구호물자가 출발하는 장소는 항상 1번이며 대피소가 있는 곳 역시 항상 N번이다
int n,t,a,flag;
vector <int> path[101];
int visited[101];
int answer;
//종료 조건 : 1번에서 갈 수 있는 모든 경로로 간 경우
//조건 : 해당 경로를 방문한 경우 & 경로를 방문하지 않은 경우
//만약 해당 경로로 이미 갈 수 없다는 게 판단된다면 return을 한다. (탐색을 완료한 visited가 -1인 경우가 해당)
void find(int idx){
    visited[idx]=1;
    for(int k=0;k<path[idx].size();k++){
        if(visited[path[idx][k]]==-1){
            return;
        }
        if(visited[path[idx][k]]==1) {
            answer=-1;
        }
        else if(visited[path[idx][k]]==0){
            find(path[idx][k]);
        }
    }
    visited[idx]=-1;
}
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>t; //개수
        for(int j=0;j<t;j++){
            cin>>a;
            a-=1;
            path[i].push_back(a);
        }
    }
    memset(visited,0,sizeof(visited));
    find(0);
    answer==-1?cout<<"CYCLE":cout<<"NO CYCLE";
    return 0;
}