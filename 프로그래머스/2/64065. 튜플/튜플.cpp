#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    stringstream ss(s.substr(1, s.size() - 2));
    string token;
    vector<string> tmp;
    while(getline(ss, token, '{')){
        while(token.back() == ',' || token.back() == '}') token.pop_back();
        tmp.push_back(token);
    }
    
    sort(tmp.begin(), tmp.end(), [](const string& a, const string& b){
        return a.size() < b.size();
    });
    
    set<int> st;
    for(string& str: tmp){
        stringstream ss2(str);
        while(getline(ss2, token, ',')){
            int cur = stoi(token);
            if(st.find(cur) != st.end()) continue;
            
            st.insert(cur);
            answer.push_back(cur);
        }
    }
    
    return answer;
}