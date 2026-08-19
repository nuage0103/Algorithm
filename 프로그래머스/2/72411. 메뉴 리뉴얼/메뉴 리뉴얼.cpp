#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um; // {course, freq}
void dfs(string& s, string& cur, int idx){
    if(cur.size() > 1) um[cur]++;
    if(idx == s.size()) return;
    
    for(int i = idx; i < s.size(); i++){
        cur.push_back(s[i]);
        dfs(s, cur, i + 1);
        cur.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto& o: orders){
        sort(o.begin(), o.end());
        string cur = "";
        dfs(o, cur, 0);
    }
    
    for(int required: course){
        int max_freq = 0;
        for(auto& [c, freq]: um){
            if(c.size() == required) max_freq = max(max_freq, freq);
        }
        if(max_freq < 2) continue;
        
        for(auto& [c, freq]: um){
            if(c.size() == required && freq == max_freq) answer.push_back(c);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}