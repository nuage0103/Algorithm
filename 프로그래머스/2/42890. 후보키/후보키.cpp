#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void dfs(int depth, int degree, int mask, set<int>& candidate){
    if(mask) candidate.insert(mask);
    if(depth == degree) return;
    
    for(int i = 0; i < degree; i++){
        if(mask & (1 << i)) continue;
        
        dfs(depth + 1, degree, mask | (1 << i), candidate);
    }
}

bool check_unique(vector<vector<string>>& relation, int mask, int degree){
    set<vector<string>> row;
    for(auto& r: relation){
        vector<string> cur;
        for(int i = 0; i < degree; i++){
            if(mask & (1 << i)) cur.push_back(r[i]);
        }
        
        if(row.find(cur) != row.end()) return false; 
        row.insert(cur);
    }
    
    return true;
}

bool check_mini(vector<int>& unique, int mask, int idx){
    for(int i = 0; i < idx; i++){
        if((mask & unique[i]) == unique[i]) return false;
    }
    
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    int degree = relation[0].size();
    // 모든 조합
    set<int> candidate;
    dfs(0, degree, 0, candidate);
    
    vector<int> unique;
    for(int cand: candidate){
        // 유일성
        if(check_unique(relation, cand, degree)) unique.push_back(cand);
    }
    
    sort(unique.begin(), unique.end());
    for(int i = 0; i < unique.size(); i++){
        if(check_mini(unique, unique[i], i)) answer++;
    }
    
    return answer;
}