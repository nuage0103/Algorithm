#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

long long cal(string& priority, vector<long long> num, vector<char> op){
    for(char cur: priority){
        for(int i = 0; i < op.size(); i++){
            if(op[i] != cur) continue;

            if(cur == '+') num[i] += num[i + 1];
            else if(cur == '-') num[i] -= num[i + 1];
            else if(cur == '*') num[i] *= num[i + 1];
            // 삭제, 이동
            num.erase(num.begin() + i + 1);
            op.erase(op.begin() + i);
            i--;
        }
    }
    
    return abs(num[0]);
}

void dfs(string& priority, string& ops, int mask, set<string>& s){
    if(priority.size() == ops.size()){
        s.insert(priority);
        return;
    }
    
    for(int i = 0; i < 3; i++){
        if(mask & (1 << i)) continue;
        
        priority += ops[i];
        dfs(priority, ops, mask | (1 << i), s);
        priority.pop_back();
    }
}

long long solution(string expression) {
    long long answer = 0;
    
    // 문자열 분리
    vector<long long> num;
    vector<char> op;
    string tmp = "";
    for(char c: expression){
        if(isdigit(c)) tmp += c;
        else{
            if(tmp.size()) num.push_back(stoll(tmp));
            tmp = "";
            op.push_back(c);
        }
    }
    if(tmp.size()) num.push_back(stoll(tmp));
    
    // 연산자 우선순위
    string operators = "+-*";
    string priority = "";
    set<string> s;
    dfs(priority, operators, 0, s);
    
    for(auto pr: s){
        // 연산
        answer = max(answer, cal(pr, num, op));
    }
    
    return answer;
}