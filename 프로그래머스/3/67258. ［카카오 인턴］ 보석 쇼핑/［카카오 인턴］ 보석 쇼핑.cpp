#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    int n = gems.size();
    int total = 0; // 전체 종류 수
    unordered_map<string, int> um; // {string, freq}
    for(auto& g: gems){
        um[g]++;
        if(um[g] == 1) total++;
    }
    
    int st = 0, en = 0;
    pair<int, int> res = {-1, n};
    int cur = 0; // 구간에 포함 종류 수
    unordered_map<string, int> um2;
    while(st < n){
        while(en < n && cur < total){
            um2[gems[en]]++;
            if(um2[gems[en]] == 1) cur++;
            en++;
        }
        
        if(cur == total){
            if(res.second - res.first > en - 1 - st){
                res = {st, en - 1};
            }
        }
        
        um2[gems[st]]--;
        if(um2[gems[st]] == 0) cur--;
        st++;
    }
    
    answer.push_back(res.first + 1);
    answer.push_back(res.second + 1);
    return answer;
}