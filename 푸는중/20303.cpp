#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
using namespace std;
int n,m,k,candy,a,b;
vector<int> c;
vector<int> f[30001];
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>candy;
        c.push_back(candy);
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        f[a].push_back(b);
        f[b].push_back(a);
    }
    return 0;
}