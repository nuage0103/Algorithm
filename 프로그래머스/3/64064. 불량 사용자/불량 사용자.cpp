#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
int b_size, u_size;
vector<vector<int>> mapping; // mapping[i]: bid[i]에 해당하는 uid idx 목록
unordered_set<int> res;

bool check(string& b, string& u){
    if(b.length() != u.length()) return false;
    for(int i=0; i<b.length(); i++){
        if(b[i] == '*') continue;
        if(b[i] != u[i]) return false;
    }
    return true;
}

void dfs(int depth, int mask){
    if(depth == b_size){
        res.insert(mask);
        return;
    }
    
    for(int i=0; i<mapping[depth].size(); i++){
        int uid = mapping[depth][i];
        if(!(mask&(1<<uid))){
            dfs(depth+1, mask|(1<<uid));
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    b_size = banned_id.size();
    u_size = user_id.size();
    mapping.resize(b_size);
    
    for(int i=0; i<b_size; i++){
        for(int j=0; j<u_size; j++){
            if(check(banned_id[i], user_id[j])) mapping[i].push_back(j);
        }
    }
    
    int answer = 0;
    dfs(0, 0);
    answer = res.size();

    return answer;
}