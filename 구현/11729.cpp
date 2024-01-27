//40분 아이디어 참고
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
using namespace std;
//3개의 탑 from, mid, to
//n개를 to로 이동하고 싶다
    //n-1개를 from에서 mid로 이동한다
    //1개를 from에서 to로 이동한다
    //n-1개를 mid에서 to로 이동한다

void hanoi(int n,int from,int mid, int to){
    if(n==0){
        return;
    }
    hanoi(n-1,from,to, mid); //2번째 원판으로 모두 이동시킨다.
    cout<<from<<" "<<to<<"\n"; //원판 n-1을 from에서 to로 옮긴다.
    hanoi(n-1,mid,from,to); //2번째 원판에서 3번째 원판으로 이동시킨다.
}

int main(){
    int n;
    cin>>n;
    cout<<(1<<n)-1<<"\n"; //n개의 원판에 대해 2,3번째 위치로 옮길 때마다 이동여부를 판단 & 마지막 맨 아래 원판은 1번의 이동
    //(1<<n) : n을 이진수로 환원한 뒤 왼쪽으로 한 칸 씩 이동 -> 2의 승수가 올라감
    hanoi(n,1,2,3);
    return 0;
}