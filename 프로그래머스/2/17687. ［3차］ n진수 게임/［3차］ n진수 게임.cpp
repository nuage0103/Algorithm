#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string convert(int n, string digit, int cur){
    if(cur == 0) return "0";
    
    string ret = "";
    while(cur){
        ret += digit[cur % n];
        cur /= n;
    }
    
    reverse(ret.begin(), ret.end());
    
    if(ret[0] == '0') return ret.substr(1);
    else return ret;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    // 원소
    string all = "0123456789ABCDEF";
    string digit = all.substr(0, n);

    // 게임
    string full_str = "";
    int cur = 0;
    while(full_str.size() < t * m){
        full_str += convert(n, digit, cur);
        cur++;
    }
    
    for(int i = p - 1; i < full_str.size(); i += m){
        answer += full_str[i];
        if(answer.size() == t) break;
    }
    
    return answer;
}