#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

bool check(string& b, string& u){
    if(u.size() != b.size()) return false;
    
    for(int j = 0; j < b.size(); j++){
        if(b[j] == '*') continue;
        if(b[j] != u[j]) return false;
    }
    return true;
}

void dfs(int depth, vector<vector<int>>& ban_idx, unordered_set<int>& s, int mask){
    if(depth == ban_idx.size()){
        s.insert(mask);
        return;
    }
    
    for(int i = 0; i < ban_idx[depth].size(); i++){
        int idx = ban_idx[depth][i];
        // 제재아이디 중복 확인
        if(mask & (1 << idx)) continue;
        
        dfs(depth + 1, ban_idx, s, mask | (1 << idx));
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vector<vector<int>> ban_idx; // 각 불량에 해당하는 제재아이디 인덱스
    ban_idx.resize(banned_id.size());
    for(int i = 0; i < banned_id.size(); i++){
        string b = banned_id[i];
        for(int j = 0; j < user_id.size(); j++){
            if(check(b, user_id[j])) ban_idx[i].push_back(j);
        }
    }
    
    unordered_set<int> s;
    dfs(0, ban_idx, s, 0);
    answer = s.size();
    return answer;
}