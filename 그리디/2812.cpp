#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;
int n,k,i,cnt;
stack<int> st;
stack<int> st2;
string num;
int result;
int main(){
    cin>>n>>k;
    cin>>num;
    for(auto s:num){
        int nnum=s-'0';
        while(!st.empty()&&st.top()<nnum && cnt<k){
            st.pop();
            cnt++;
        }
        if(st.size()<n-k){
            st.push(nnum);
        }
    } 
    while (!st.empty()){
        st2.push(st.top());
        st.pop();
    }
    while (!st2.empty()){
        cout << st2.top();
        st2.pop();
    }
    // int ten=1;
    // while(!st.empty()){
    //     result+=st.top()*ten;
    //     st.pop();
    //     ten*=10;
    // }
    // cout<<result;
    return 0;
}