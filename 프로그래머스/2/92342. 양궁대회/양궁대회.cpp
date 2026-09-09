#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
k점: a어피치, b라이언. a>=b 어피치+k, a<b 라이언+k (a>0, b>0)
최종점수 A, B. A>=B 어피치 승, A<B 라이언 승

*/

int max_diff;
vector<int> lion_res;

void update(const vector<int>& peach, const vector<int>& lion){
    int p_sum = 0, l_sum = 0;
    for(int i = 0; i <= 10; i++){
        if(!peach[i] && !lion[i]) continue;
        
        if(peach[i] >= lion[i]) p_sum += (10 - i);
        else l_sum += (10 - i);
    }
    
    int diff = l_sum - p_sum;
    if(diff <= 0) return;
    
    if(diff > max_diff){
        max_diff = diff;
        lion_res = lion;
    }
    else if(diff == max_diff){
        for(int i = 10; i >= 0; i--){
            if(lion[i] > lion_res[i]){
                lion_res = lion;
                return;
            }
            if(lion_res[i] > lion[i]) return;
        }
    }
}

void dfs(const vector<int>& peach, vector<int>& lion, int depth, int cur, int n){
    if(depth == 11){
        if(cur < n) lion[10] += (n - cur);
        update(peach, lion);
        if(cur < n) lion[10] -= (n - cur);
        return;
    }
    
    // 점수x
    lion[depth] = 0;
    dfs(peach, lion, depth + 1, cur, n);
    // 점수o
    if(cur + peach[depth] + 1 <= n){
        lion[depth] = peach[depth] + 1;
        dfs(peach, lion, depth + 1, cur + peach[depth] + 1, n);
        lion[depth] = 0;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    // info[i] = (10-i)점 개수    
    max_diff = -1;
    lion_res.assign(11, 0);
    vector<int> lion(11);
    dfs(info, lion, 0, 0, n);
    
    if(max_diff == -1) return {-1};
    else answer = lion_res;
    
    return answer;
}