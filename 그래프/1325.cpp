#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int n,m,a,b,turn,com;
int maxA=-1e9;
vector<pair<int,int>> answer;
// A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다
// 첫째 줄에, N과 M이 들어온다. N은 10,000보다 작거나 같은 자연수, M은 100,000보다 작거나 같은 자연수이다.
//  둘째 줄부터 M개의 줄에 신뢰하는 관계가 A B와 같은 형식으로 들어오며, "A가 B를 신뢰한다"를 의미한다.
//  컴퓨터는 1번부터 N번까지 번호가 하나씩 매겨져 있다.
vector <int> t[10001];
int visited[10001];
void dfs(int idx){
    // if(t[idx].size()==0){return;}
    visited[idx]=1;
    com++;
    for(int i=0;i<t[idx].size();i++){
        if(visited[t[idx][i]]==1){continue;}
        dfs(t[idx][i]);
    }       
}
int main(){
    cin>>n>>m;
    memset(t,0,sizeof(int)*n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a-=1;
        b-=1;
        t[b].push_back(a);
    }
    for(int j=0;j<n;j++){
        com=0;
        memset(visited,0,sizeof(int)*n);
        dfs(j); //해당 인덱스로부터 해킹할 수 있는 컴퓨터 개수
        answer.push_back({-com,j});
    }
    sort(answer.begin(),answer.end());
    int tmp=-answer[0].first;
    cout<<answer[0].second+1;
    for(int i=1;i<n;i++){
        if(tmp==-answer[i].first){
            cout<<" "<<answer[i].second+1;
        }
    }
    
}