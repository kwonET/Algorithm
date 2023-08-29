#include <cstdio>
#include <algorithm>
#include <vector>
#define INT_MAX 1e9;
using namespace std;
int n,k,i,j,target;
struct Stu{
    Stu(int id, int rec, int index):id(id), rec(rec), index(index){}
    int id,rec, index;
};
vector<Stu> frame;
bool comp(Stu &a, Stu &b){
    return a.id<b.id ;
}
int main(){
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<k;i++){
        int flag=0;
        scanf("%d",&target);

        //0. 처음 게시되는 상황
        if(frame.size()==0){
            frame.push_back(Stu(target,1,i));
            continue;
        }

        //1. 현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우에는 추천받은 횟수만 증가시킨다.
        for(j=0;j<n;j++){
            if(frame[j].id==target){
                frame[j].rec++;
                flag=1;
            }
        }

        if(flag==0){
            //2. 틀이 빈 상황
            if(frame.size()<n){
                frame.push_back(Stu(target,1,i));
                continue;
            }
            //3. 틀이 비지 않은 상황
            if(frame.size()==n){
                int min_r=INT_MAX;
                int min_i=-1;
                for(j=0;j<n;j++){
                    if(frame[j].rec<min_r){
                        min_r=frame[j].rec;
                        min_i=j;
                    }
                    else if(frame[j].rec==min_r){
                        if(frame[min_i].index>frame[j].index){
                            min_i=j;
                        }
                    }
                }
                frame[min_i]=Stu(target,1,i);
            }
        }
    }

    sort(frame.begin(),frame.end(),comp);
    for(i=0;i<n;i++){
        if(frame[i].rec!=0){
            printf("%d ",frame[i].id);
        }
    }
    return 0;
}