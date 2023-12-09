#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,i,a,result,sum;
priority_queue<int> cards;
int main(){
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        cards.push(-a); // 작은 수부터 정렬되게
    }
    // 원소가 1개인 경우엔 합치는 경우의 수가 존재하지 않음
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    while(!cards.empty()){
        sum=0;
        for(i=0;i<2;i++){ //2개씩 짝지어서 뽑음
            sum+=-cards.top();
            cards.pop();
        }
        result+=sum;
        if(!cards.empty()){
            cards.push(-sum); //2개를 더한 것을 추가
        }
    }
    cout<<result;
    return 0;
}