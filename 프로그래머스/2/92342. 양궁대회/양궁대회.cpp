#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> r_info(11);
int max_diff;
vector<int> tmp(11);

void update_r(int n, vector<int>& info){
    int a_sum = 0, tmp_sum = 0;
    for(int i = 0; i <= 10; i++){
        if(info[i] == 0 && tmp[i] == 0) continue;
        
        if(info[i] >= tmp[i]) a_sum += (10 - i);
        else tmp_sum += (10 - i);
    }
    
    if(a_sum < tmp_sum){
        int tmp_diff = tmp_sum - a_sum;
        
        if(max_diff < tmp_diff){
            max_diff = tmp_diff;
            r_info = tmp;
        }
        else if(max_diff == tmp_diff){
            for(int i = 10; i >= 0; i--){
                if(r_info[i] == tmp[i]) continue;
                else {
                    if(r_info[i] < tmp[i]){
                        r_info = tmp;
                    }
                    break;
                }
            }
        }
    }
    
}

void dfs(int n, vector<int>& info, int depth, int cnt){
    if(cnt == n){
        update_r(n, info);
        return;
    }
    
    if(depth == 11){
        if(cnt < n) tmp[10] += (n - cnt);
        update_r(n, info);
        if(cnt < n) tmp[10] -= (n - cnt);
        return;
    }

    for(int i = 0; i <= n; i++){
        if(cnt + i > n) continue;
        tmp[depth] = i;
        dfs(n, info, depth + 1, cnt + i);
        tmp[depth] = 0;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    max_diff = -1;
    dfs(n, info, 0, 0);
    
    if(max_diff == -1) answer.push_back(-1);
    else answer = r_info;
    
    return answer;
}