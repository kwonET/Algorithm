#include <iostream>
#include <vector>
using namespace std;
int n, a,s,result;
vector <int>arr;
void dfs(int idx,int sum){
    if(idx==n){
        if(sum==s){
            result+=1;
        }return;
    }
    dfs(idx+1,sum);//현재 원소를 더하지 않거나 
    dfs(idx+1,sum+arr[idx]);//더하거나
}
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n;i++){
        cin >> a;
        arr.push_back(a);
    }
    dfs(0,0);
    if(s==0){result-=1;}
    cout<<result;
    return 0;
}