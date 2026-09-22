#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> lang = {
    {"cpp", 1},
    {"java", 2},
    {"python", 3}
};
map<string, int> group = {
    {"backend", 1},
    {"frontend", 2}
};
map<string, int> career = {
    {"junior", 1},
    {"senior", 2}
};
map<string, int> food = {
    {"chicken", 1},
    {"pizza", 2}
};

vector<int> convert(string& s, int mode){
    vector<int> ret;
    stringstream ss(s);
    string l, g, c, f;
    int x;
    if(mode){
        string delim;
        ss >> l >> delim >> g >> delim >> c >> delim >> f >> x;
    }
    else{
        ss >> l >> g >> c >> f >> x;
    }

    
    int val = (l == "-")? -1 : lang[l];
    ret.push_back(val);
    
    val = (g == "-")? -1 : group[g];
    ret.push_back(val);
    
    val = (c == "-")? -1 : career[c];
    ret.push_back(val);
    
    val = (f == "-")? -1 : food[f];
    ret.push_back(val);
    
    ret.push_back(x);
    
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    int n = info.size();
    map<vector<int>, vector<int>> key_score;
    for(int i = 0; i < n; i++){
        vector<int> tmp = convert(info[i], 0);
        
        // key 조합 16가지: key[i] = {값/-1}
        for(int mask = 0; mask < 16; mask++){
            vector<int> key; // 점수 외
            for(int j = 0; j < 4; j++){
                if(mask & (1 << j)) key.push_back(tmp[j]);
                else key.push_back(-1);
            }
            
            key_score[key].push_back(tmp[4]);
        }
    }
    
    for(auto& [k, v]: key_score){
        sort(v.begin(), v.end()); // 점수 오름차순
    }

    for(string& q: query){
        vector<int> tmp = convert(q, 1);
        vector<int> key = {tmp[0], tmp[1], tmp[2], tmp[3]};
        vector<int>& score = key_score[key];
        // 점수 미만: 0~idx-1
        int idx = lower_bound(score.begin(), score.end(), tmp[4]) - score.begin();
        
        answer.push_back(score.size() - idx);
    }
    return answer;
}