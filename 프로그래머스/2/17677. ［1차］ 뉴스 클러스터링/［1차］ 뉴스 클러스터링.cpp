#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

set<string> common;

vector<string> make_set(string& str){
    // 소문자 변환
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    
    // 두글자씩 끊기
    vector<string> st;
    for(int i = 0; i < str.size() - 1; i++){
        if(str[i] < 'a' || str[i] > 'z') continue;
        if(str[i + 1] < 'a' || str[i + 1] > 'z') continue;
    
        st.push_back(str.substr(i, 2));
    }
    
    return st;
}

unordered_map<string, int> cnt_set(vector<string> st){
    unordered_map<string, int> um;
    for(const auto& str: st){
        if(um.find(str) == um.end()){
            um[str] = 1;
            common.insert(str);
        }
        else{
            um[str]++;
        }
    }
    
    return um;
}

int solution(string str1, string str2) {
    int answer = 65536;
    /*
    J(A, B)는 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈 값
    중복 원소: 교집합 min, 합집합 max
    */
    unordered_map<string, int> um1 = cnt_set(make_set(str1));
    unordered_map<string, int> um2 = cnt_set(make_set(str2));
    
    float inter = 0, uni = 0;
    for(auto& cur: common){
        int cnt1 = um1.find(cur) == um1.end()? 0 : um1[cur];
        int cnt2 = um2.find(cur) == um2.end()? 0 : um2[cur];
        
        inter += min(cnt1, cnt2);
        uni += max(cnt1, cnt2);
    }
    
    if(inter == 0 && uni == 0) answer *= 1;
    else answer *= (inter / uni);
    
    return answer;
}