#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int i,j,l,c,mo,ja;
char tmp;
vector<char> balpha;
bool alpha[16];
void dfs(int s,int cnt){
    if(cnt==l){ //원하는 암호 개수만큼 되면 검사
        mo=0,ja=0;
        for(i=0;i<c;i++){
            if(alpha[i]){ //해당 알파벳이 포함되었는지를 확인
                char target=balpha[i];
                if(target=='a'||target=='e'||target=='i'||target=='o'||target=='u'){mo++;}
                else{ja++;}
            }
        }
        if(mo>=1&&ja>=2){
            for(i=0;i<c;i++){
                if(alpha[i]){
                    printf("%c",balpha[i]);
                }
            }
            printf("\n");
        }
       return; 
    }
    for(int j=s;j<c;j++){ //alpha 배열에서 시작한 인덱스 s부터 c개만큼 순회
        if(alpha[j]==true) continue;//아직 안 고른 알파벳에 대하여
        alpha[j]=true;
        dfs(j,cnt+1);
        alpha[j]=false;
    }
}
int main(){
    scanf("%d %d",&l,&c);
    for(i=0;i<c;i++){
        getchar();
        scanf("%c",&tmp);
        balpha.push_back(tmp);
    }
    sort(balpha.begin(),balpha.end());
    dfs(0,0);
    return 0;
}