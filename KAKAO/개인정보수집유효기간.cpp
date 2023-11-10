// https://school.programmers.co.kr/learn/courses/30/lessons/150370
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector <int> answer;
    int i,j,k;
    int year, month,day,total, pyear, pmonth,pday,ptotal,tmonth;
    map<char, int> parsedterm;
    
    year = stoi(today.substr(0, 4)); 
    month = stoi(today.substr(5, 2)); //시작 위치, 개수
    day = stoi(today.substr(8, 2));
    total = year * 12 * 28 + (month - 1) * 28 + day;
    
    for(j=0;j<terms.size();j++){ //약관 | 유효기간
        stringstream ss(terms[j]);
        char alpha; int tmonth;
        ss>>alpha>>pmonth;
        parsedterm[alpha]=pmonth;
    }

    for(i=0;i<privacies.size();i++){//모든 정보에 대해 탐색
        pyear=stoi(privacies[i].substr(0,4));
        pmonth=stoi(privacies[i].substr(5,2));
        pday=stoi(privacies[i].substr(8,2));
        ptotal=pyear*12*28+(pmonth-1)*28+pday;
        
        char pterm=privacies[i].back();
        
        if(ptotal+parsedterm[pterm]*28-1<total){
            answer.push_back(i+1);
        }
            
    }
    
    return answer;
}

