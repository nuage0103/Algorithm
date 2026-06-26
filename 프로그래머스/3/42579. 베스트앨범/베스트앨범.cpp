#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int n = genres.size();
    unordered_map<string, int> total; // {장르, 횟수 합}
    unordered_map<string, vector<pair<int, int>>> same_gen; // {장르, {횟수, 고유번호}}
    for(int i = 0; i < n; i++){
        total[genres[i]] += plays[i];
        same_gen[genres[i]].push_back({plays[i], i});
    }
    vector<pair<string, int>> gen_order(total.begin(), total.end());
    // 장르 별 횟수 내림차순 정렬
    sort(gen_order.begin(), gen_order.end(), [](const auto& a, const auto& b){
        return a.second > b.second;
    });
    
    for(auto& [g, v]: gen_order){
        auto& tmp = same_gen[g];
        
        // 동일 장르: 횟수, 고유번호(원본 인덱스)
        sort(tmp.begin(), tmp.end(), [](const auto& a, const auto& b){
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
        
        answer.push_back(tmp[0].second);
        if(tmp.size() > 1) answer.push_back(tmp[1].second);
    }
    
    return answer;
}