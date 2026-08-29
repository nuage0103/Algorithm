#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(int depth, int n, vector<int>& cur, int idx, vector<vector<int>>& res){
    if(depth == 5){
        res.push_back(cur);
        return;
    }
    
    for(int i = idx; i <= n; i++){
        cur[depth] = i;
        dfs(depth + 1, n, cur, i + 1, res);
    }
}

bool check(vector<int>& r, const vector<vector<int>>& q, const vector<int>& ans){
    int m = q.size();
    
    for(int i = 0; i < m; i++){
        // r, q[i] 모두 오름차순
        int ri = 0, qi = 0;
        int same = 0;
        while(ri != 5 && qi != 5){
            if(r[ri] == q[i][qi]){
                same++;
                ri++;
                qi++;
            }
            else if(r[ri] > q[i][qi]) qi++;
            else ri++;
        }

        if(same != ans[i]) return false;
    }

    return true;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    vector<int> cur(5);
    vector<vector<int>> res; // 1~n 5개 숫자 조합
    dfs(0, n, cur, 1, res);
    
    for(auto& r: res){
        if(check(r, q, ans)) answer++;
    }
    
    return answer;
}