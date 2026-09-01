#include <string>
#include <vector>
#include <iostream>

using namespace std;

pair<int, int> cal(vector<int>& emoticons, vector<int>& discount, vector<vector<int>>& users){
    pair<int, int> ret = {0, 0}; // {가입인원수, 판매이익}
    
    for(int i = 0; i < users.size(); i++){
        int u_dis = users[i][0];
        int u_total = users[i][1];
        int total = 0;
        
        for(int j = 0; j < emoticons.size(); j++){
            int a = emoticons[j];
            int dis = discount[j];
            if(dis < u_dis) continue;
            else total += a * (100 - dis) / 100;
            
            if(u_total <= total) break;
        }
        
        if(u_total <= total){
            ret.first++;
        }
        else{
            ret.second += total;
        }
    }
    
    return ret;
}

pair<int, int> res;

void dfs(int depth, vector<int>& emoticons, vector<int>& discount, vector<vector<int>>& users){
    if(depth == emoticons.size()){
        // 가입자마다 구매 비용 연산, 가입 여부 판단
        res = max(res, cal(emoticons, discount, users));
        return;
    }
    
    for(int i = 10; i <= 40; i += 10){
        discount[depth] = i;
        dfs(depth + 1, emoticons, discount, users);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer; // [0]: 가입인원수, [1]: 판매이익
    
    // 할인율 적용
    vector<int> discount(emoticons.size());
    res = {0, 0};
    dfs(0, emoticons, discount, users);
    
    answer.push_back(res.first);
    answer.push_back(res.second);
    
    return answer;
}