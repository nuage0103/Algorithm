#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(string& s){
    string tmp = "";
    for(char c: s){
        if(c == '(') tmp += c;
        else{
            if(tmp.back() == '(') tmp.pop_back();
        }
    }
    
    return (tmp.size() == 0);
}

string sol(string& w){
    if(w.size() == 0) return "";
    
    string ret = "";
    string u = "", v = "";
    int left = 0, right = 0;
    bool flag = true;
    for(char c: w){
        if(c == '(') left++;
        else right++;
        
        if(flag) u += c;
        else v += c;
        
        if(left && right && left == right) flag = false;
    }
    
    if(check(u)){
        ret += u;
        ret += sol(v);
    }
    else{
        // 4-1
        string tmp = "";
        tmp += '(';
        // 4-2
        tmp += sol(v);
        // 4-3
        tmp += ')';
        // 4-4 
        // 첫번째 제거
        reverse(u.begin(), u.end());
        u.pop_back();
        // 마지막 제거
        reverse(u.begin(), u.end());
        u.pop_back();
        for(char& c: u){
            if(c == '(') c = ')';
            else c = '(';
        }
        tmp += u;
        
        ret += tmp;
    }

    return ret;
}

string solution(string p) {
    string answer = "";
    answer = sol(p);
    return answer;
}