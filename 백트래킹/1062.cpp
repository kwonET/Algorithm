#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int n,k,i,j,p,cnt,result,walpha;
bool isR;
string word[51];
string tmp;
bool alpha[26];
void dfs(int calpha, int cnt){
    if(cnt==k-5){
        walpha=0;
        for(i=0;i<n;i++){
            isR=true;
            for(j=0;j<word[i].size();j++){ 
                if(alpha[word[i][j]-'a']==false){
                    isR=false;
                    break;
                }
            }
            if(isR) {walpha++;}
        }
        result=max(result,walpha);
        return;
    }
    for(int c=calpha;c<26;c++){
        if(alpha[c]==true) continue;
        alpha[c]=true;
        dfs(c,cnt+1);
        alpha[c]=false;
    }
}
int main(){
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        cin>>tmp;
        word[i]=tmp;
    }

    if(k<5){
        printf("%d",0);
        return 0;
    }
    alpha['a'-'a']=true; 
    alpha['c'-'a']=true; 
    alpha['n'-'a']=true; 
    alpha['t'-'a']=true; 
    alpha['i'-'a']=true;
    dfs(0,0);
    printf("%d ",result);
    return 0;
}