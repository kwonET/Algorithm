#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>
#define INT_MAX 1e9
using namespace std;
int w,h,g,i,j,k;
int a,b,e,x,y,t;
int dy[4]={-1,1,0,0}, dx[4]={0,0,-1,1};
int result,nflag;
int map[31][31],dist[31][31];
struct Info{
    Info(int x, int y, int a, int b, int c):x(x),y(y),a(a),b(b),c(c){}
    int x,y,a,b,c;
};
vector<Info> mInfo;
int main(){
    while(true){
        mInfo.clear();
        memset(map,0,sizeof(map));
        nflag=0;
        for(i=0;i<31;i++){ 
            for(j=0;j<31;j++){
                dist[i][j]=INT_MAX;
            }  
        }
        scanf("%d %d", &w,&h);
        if(w==0 && h==0)break;
        scanf("%d",&g);
        for(i=0;i<g;i++){
            scanf("%d %d",&a,&b);
            map[a][b]=1; //비석
        }
        scanf("%d",&e);
        for(i=0;i<e;i++){
            scanf("%d %d %d %d %d",&x,&y,&a,&b,&t);
            mInfo.push_back(Info(x,y,a,b,t));
            map[x][y]=-1; //귀신구멍
        }
        for(j=0;j<w;j++){
            for(i=0;i<h;i++){
                if((j==w-1 && i==h-1) || map[j][i]) continue; //비석 혹은 묘비구멍은 탐색 x
                for(k=0;k<4;k++){
                    int ny=i+dy[k]; int nx=j+dx[k];
                    if(ny>=h || ny<0 || nx>=w || nx<0) continue;
                    if(map[nx][ny]==1) continue; // 사분탐색한 곳이 비석일 경우 탈출
                    mInfo.push_back(Info(j,i,nx,ny,1));
                }
            }
        }
        dist[0][0]=0;
        for(i=1;i<=w*h;i++){
            for(Info list:mInfo){
                if(dist[list.x][list.y]<INT_MAX && dist[list.x][list.y]+list.c<dist[list.a][list.b]){
                    dist[list.a][list.b]=dist[list.x][list.y]+list.c;
                    if(i==w*h) {nflag=1;}
                }
            }
        }
        if(nflag==1){printf("Never\n");}
        else if (dist[w-1][h-1]<INT_MAX){printf("%d\n",dist[w-1][h-1]);}
        else{printf("Impossible\n");}              
    }
    return 0;
}