#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_map<string, int> um;
    int g_len = gems.size();
    int n = 0; // 보석 종류
    for(int i = 0; i < g_len; i++){
        um[gems[i]]++;
        if(um[gems[i]] == 1) n++;
    }
    
    pair<int, int> ans = {0, g_len};
    int st = 0, en = 0;
    unordered_map<string, int> tmp;
    int cnt = 0; // 구간에 포함된 종류
    while(st < g_len){
        while(en < g_len && cnt < n){
            tmp[gems[en]]++;
            if(tmp[gems[en]] == 1) cnt++;
            
            en++;
        }
        if(cnt == n){
            if(((en - 1) - st) < (ans.second - ans.first)) ans = {st, en - 1};
        }
        
        tmp[gems[st]]--;
        if(tmp[gems[st]] == 0) cnt--;
        st++;
    }
    
    vector<int> answer;
    answer.push_back(ans.first + 1);
    answer.push_back(ans.second + 1);
    
    return answer;
}