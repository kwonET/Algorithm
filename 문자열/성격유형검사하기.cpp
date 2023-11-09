// https://school.programmers.co.kr/learn/courses/30/lessons/118666

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;
int i; char ch;
map <char,int> total;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for(i=0;i<survey.size();i++){
        if(choices[i]<=3){
            ch=survey[i][0];
            total[ch]+=4-choices[i];
        }
        else if(choices[i]>4){
            ch=survey[i][1];
            total[ch]+=(choices[i]-4);
        }
    }
    answer+=total['R']>=total['T']?'R':'T';
    answer+=total['C']>=total['F']?'C':'F';
    answer+=total['J']>=total['M']?'J':'M';
    answer+=total['A']>=total['N']?'A':'N';
    return answer;
}