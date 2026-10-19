#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

void dfs(int depth, const vector<string>& info, string cur, map<string, vector<int>>& m){
    if(depth == 4){
        int score = stoi(info.back());
        m[cur].push_back(score);
        return;
    }
    
    dfs(depth + 1, info, cur + info[depth], m);
    dfs(depth + 1, info, cur + "-", m);
}

vector<string> convert_info(string& info){
    stringstream ss(info);
    string l, g, c, f;
    int x;
    ss >> l >> g >> c >> f >> x;
    
    vector<string> ret;
    ret.push_back(l);
    ret.push_back(g);
    ret.push_back(c);
    ret.push_back(f);
    ret.push_back(to_string(x));
    return ret;
}

pair<string, int> convert_query(string& query){
    stringstream ss(query);
    string l, g, c, f, delim;
    int x;
    ss >> l >> delim >> g >> delim >> c >> delim >> f >> x;
    
    string key = l + g + c + f;
    return {key, x};
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int>> key_score;
    
    for(string& i: info){
        dfs(0, convert_info(i), "", key_score);
    }
    
    for(auto& [k, v]: key_score){
        sort(v.begin(), v.end());
    }
    
    for(string& q: query){
        auto [key, score] = convert_query(q);
        
        auto& scores = key_score[key];
        int idx = lower_bound(scores.begin(), scores.end(), score) - scores.begin();
        int cnt = scores.size() - idx;
        answer.push_back(cnt);
    }
    return answer;
}