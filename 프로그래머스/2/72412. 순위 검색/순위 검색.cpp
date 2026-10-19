#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

unordered_map<string, int> lang = {
    {"cpp", 0}, {"java", 1}, {"python", 2}, {"-", -1}
};
unordered_map<string, int> group = {
    {"backend", 0}, {"frontend", 1}, {"-", -1}
};
unordered_map<string, int> career = {
    {"junior", 0}, {"senior", 1}, {"-", -1}
};
unordered_map<string, int> food = {
    {"chicken", 0}, {"pizza", 1}, {"-", -1}
};

vector<int> convert_info(string& info){
    stringstream ss(info);
    string l, g, c, f;
    int x;
    ss >> l >> g >> c >> f >> x;
    
    vector<int> ret;
    ret.push_back(lang[l]);
    ret.push_back(group[g]);
    ret.push_back(career[c]);
    ret.push_back(food[f]);
    ret.push_back(x);
    return ret;
}

vector<int> convert_query(string& query){
    stringstream ss(query);
    string l, g, c, f, delim;
    int x;
    ss >> l >> delim >> g >> delim >> c >> delim >> f >> x;
    
    vector<int> ret;
    ret.push_back(lang[l]);
    ret.push_back(group[g]);
    ret.push_back(career[c]);
    ret.push_back(food[f]);
    ret.push_back(x);
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<vector<int>, vector<int>> key_score;
    
    vector<int> cur;
    for(string& s: info){
        cur.clear();
        cur = convert_info(s);
        
        int score = cur.back();
        for(int mask = 0; mask < 16; mask++){
            vector<int> key;
            for(int i = 0; i < 4; i++){
                if(mask & (1 << i)) key.push_back(cur[i]);
                else key.push_back(-1);
            }
            key_score[key].push_back(score);
        }
    }
    
    for(auto& [k, v]: key_score){
        sort(v.begin(), v.end());
    }
    
    for(string& q: query){
        cur.clear();
        cur = convert_query(q);
        
        int query_score = cur.back();
        cur.pop_back();
        
        auto& scores = key_score[cur];
        int idx = lower_bound(scores.begin(), scores.end(), query_score) - scores.begin();
        int cnt = scores.size() - idx;
        answer.push_back(cnt);
    }
    return answer;
}