#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int n = genres.size();
    unordered_map<string, int> um; // {장르, 횟수 합}
    for(int i = 0; i < n; i++){
        um[genres[i]] += plays[i];
    }
    vector<pair<string, int>> freq(um.begin(), um.end());
    // 장르 별 횟수 내림차순 정렬
    sort(freq.begin(), freq.end(), [](const auto& a, const auto& b){
        return a.second > b.second;
    });
    
    for(int f = 0; f < freq.size(); f++){
        string g = freq[f].first;
        
        vector<pair<int, int>> tmp;
        for(int i = 0; i < n; i++){
            if(genres[i] != g) continue;
            
            tmp.push_back({plays[i], i});
        }
        // 동일 장르: 횟수, 고유번호(원본 인덱스)
        sort(tmp.begin(), tmp.end(), [](const auto& a, const auto& b){
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
        
        answer.push_back(tmp[0].second);
        if(tmp.size() > 1) answer.push_back(tmp[1].second);
        tmp.clear();
    }
    return answer;
}