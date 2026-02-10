#include <bits/stdc++.h>

using namespace std;

void dfs(int depth, int cur, vector<int>& d_idx, vector<vector<int>>& dice, vector<int>& sum){
    if(depth == d_idx.size()){
        sum.push_back(cur);
        return;
    }
    
    int idx = d_idx[depth];
    for(int i=0; i<6; i++){
        dfs(depth+1, cur+dice[idx][i], d_idx, dice, sum);
    }
}

int comp(vector<int>& a, vector<int>& b){
    int win = 0;
    for(int i=0; i<a.size(); i++){
        win += lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    return win;
}

vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    int k = n/2;
        
    vector<int> answer;
    answer.resize(k);
    int max_win = 0;
    for(int b=(1<<k)-1; b<(1<<n); b++){
        vector<int> a_dice; // 주사위 번호
        vector<int> b_dice;
        
        for(int i=0; i<n; i++){
            if(b & (1<<i)) a_dice.push_back(i);
            else b_dice.push_back(i);
            if(a_dice.size() > k || b_dice.size() > k) break;
        }
        if(a_dice.size() != k || b_dice.size() != k) continue;
        
        vector<int> a_sum;
        vector<int> b_sum;
        dfs(0, 0, a_dice, dice, a_sum);
        dfs(0, 0, b_dice, dice, b_sum);
        
        sort(b_sum.begin(), b_sum.end());
        
        int win = comp(a_sum, b_sum);
        if(max_win < win){
            max_win = win;
            for(int i=0; i<k; i++) answer[i] = a_dice[i] + 1;
        }
    }
    
    return answer;
}