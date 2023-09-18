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
    // a, c, n, i, t를 제외한 가르칠 수 있는 K개의 알파벳을 다 가르친 경우
    if(cnt==k-5){
        walpha=0;
        for(i=0;i<n;i++){
            isR=true;
            for(j=0;j<word[i].size();j++){ 
                //단어의 알파벳 중 안 가르친 알파벳이 있다면 중단
                if(alpha[word[i][j]-'a']==false){
                    isR=false;
                    break;
                }
            }
            if(isR) {walpha++;} //모든 알파벳을 다 가르친 경우 -> 해당 단어는 가르친 것
        }
        result=max(result,walpha);
        return;
    }
    //알파벳을 순회하며 가르칠 알파벳에 대해 조합을 구해본다
    for(int c=calpha;c<26;c++){
        if(alpha[c]==true) continue;
        alpha[c]=true;
        dfs(c,cnt+1);
        alpha[c]=false; //다른 조합을 위해 검사를 완료한 알파벳은 false로 변경
    }
}
int main(){
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        cin>>tmp;
        word[i]=tmp;
    }
    // k개 5개 미만이면 기본적인 알파벳 a, c, n, i, t을 가르칠 수 없다. -> 즉 가르칠 수 있는 단어가 없다
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