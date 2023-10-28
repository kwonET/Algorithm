#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,A[1025][1025],i,j,r,c,x1,y1,x2,y2,result;
x=0;
for(i=1;i<=n;i++)
    for(j=1;j<=i*i;j++)
        if(j%i==0)
        for(k=1;k<=j;k++)
            x++;

int main(){
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(r=0;r<n;r++){
        for(c=0;c<n;c++){
            if(r==0 && c==0){
                continue;
            }
            if(r==0){
                A[r][c]=A[r][c-1]+A[r][c]; continue;
            }
            if(c==0){
                A[r][c]=A[r-1][c]+A[r][c]; continue;
            }
            A[r][c]=A[r][c-1]+A[r-1][c]-A[r-1][c-1]+A[r][c];
        }  
    }
        
    for(i=0;i<m;i++){
        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
        y1-=1;x1-=1;y2-=1;x2-=1;
        if(x1==0 && y1==0){
            result=A[y2][x2]; 
            printf("%d\n",result); continue;
        }
        if(x1==0){
            result=A[y2][x2]-A[y1-1][x2];
            printf("%d\n",result); continue;
        }
        if(y1==0){
            result=A[y2][x2]-A[y2][x1-1];
            printf("%d\n",result); continue;
        }
        result=A[y2][x2]-A[y2][x1-1]-A[y1-1][x2]+A[y1-1][x1-1];
        printf("%d\n",result);
    }
    return 0;
}