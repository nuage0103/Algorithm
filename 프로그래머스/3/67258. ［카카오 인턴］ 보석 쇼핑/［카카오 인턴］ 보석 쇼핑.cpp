#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int n = 0; // 종류
    int len = gems.size();
    unordered_map<string, int> name_cnt;
    for(auto& gem: gems){
        name_cnt[gem]++;
        if(name_cnt[gem] == 1) n++;
    }
    
    if(n == 1) return {1, 1};
    
    int st = 0, en = 1;
    unordered_map<string, int> um;
    answer.push_back(0);
    answer.push_back(len);
    um[gems[st]]++;
    int cur = 1;
    while(st < len){
        while(en < len && cur < n){
            um[gems[en]]++;
            if(um[gems[en]] == 1) cur++;
            en++;
        }
        
        if(cur == n){
            if(answer[1] - answer[0] + 1 > en - st){
                // 0base: st~en-1
                // 1base
                answer[0] = st + 1;
                answer[1] = en;
            }
        }
        
        um[gems[st]]--;
        if(um[gems[st]] == 0) cur--;
        st++;
    }
    return answer;
}