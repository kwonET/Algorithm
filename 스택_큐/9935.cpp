#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
using ll=long long;
using pii =pair<int,int>;
using pll=pair<ll,ll>;
#define all(v) v.begin(),v.end()

stack <char> st;
string s1,s2;
int s_size=0;
void check(){
    for(auto s:s1){
        st.push(s);
        if(s==s2[s_size-1]&&st.size()>=s_size){
            string tmp;
            for(int i=0;i<s_size;i++){
                tmp.push_back(st.top());
                st.pop();
            }
            reverse(tmp.begin(),tmp.end());
            //문자열이 같지 않은 경우
            if(tmp.compare(s2)!=0){
                for(int i=0;i<tmp.length();i++){
                    st.push(tmp[i]);
                }
            }
        }
    }

    if(st.empty()){
        cout<<"FRULA";
    }else{
        string result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        cout<<result;
    }
}
// 주어진 문자열을 stack에 넣을때
// 타겟 문자열의 맨 위에 글자와 다르다면 그냥 push
// 만약 같다면 타겟 문자열만큼 꺼내와 같은지 판단
// 다르면 다시 넣는다
// 이런식으로 주어진 문자열을 모두 넣으면 남은 문자열이 저압이 된다.
void solve(){
    char a;
    cin>>s1>>s2;
    for(auto s:s2){
        s_size++;
    }
    check();
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
    return 0;
}