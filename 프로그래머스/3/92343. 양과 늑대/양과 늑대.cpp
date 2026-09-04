#include <string>
#include <vector>
#include <iostream>

using namespace std;

int max_sheep;

void dfs(const vector<int>& info, const vector<vector<int>>& childs, int sh, int wo, int mask){
    max_sheep = max(max_sheep, sh);
    
    for(int i = 0; i < info.size(); i++){
        if(!(mask & (1 << i))) continue;
        
        int next_sh = (!info[i])? sh + 1 : sh;
        int next_wo = (info[i])? wo + 1 : wo;
        if(next_sh <= next_wo) continue;
        
        int next_mask = mask;
        for(int nx: childs[i]) next_mask |= (1 << nx);
        next_mask &= ~ (1 << i);
        dfs(info, childs, next_sh, next_wo, next_mask);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    // 양<=늑대 잡힙
    // 0 루트
    // edges[i] = {pa, ch}
    vector<vector<int>> childs(info.size());
    for(auto& e: edges){
        childs[e[0]].push_back(e[1]);
    }
    
    max_sheep = 0;
    // mask: 이동 가능한 노드
    int mask = 0;
    for(int x: childs[0]) mask |= (1 << x);
    dfs(info, childs, 1, 0, mask);
    answer = max_sheep;
    
    return answer;
}