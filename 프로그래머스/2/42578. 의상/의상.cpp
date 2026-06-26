#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, int> um; // {종류, 개수}
    for(int i = 0; i < clothes.size(); i++){
        // clothes: {이름, 종류}
        um[clothes[i][1]]++;
    }
    
    // 개수 = 종류별 개수 + 1(선택안함)
    // answer = 개수들 곱 - 1
    answer = 1;
    for(auto& [k, v]: um){
        answer *= (v + 1);
    }
    answer -= 1;
    
    return answer;
}