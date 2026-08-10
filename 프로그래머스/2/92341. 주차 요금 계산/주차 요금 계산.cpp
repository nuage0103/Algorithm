#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    // 시간, 번호, 입출
    // {번호: {시간 벡터}}
    unordered_map<string, vector<int>> um;
    for(auto& r: records){
        stringstream ss(r);
        string time, num, inout;
        ss >> time >> num >> inout;
        int hr = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3));
        um[num].push_back(hr * 60 + min);
    }
    
    for(auto& [num, time]: um){
        if(time.size() % 2 != 0) um[num].push_back(23 * 60 + 59);
    }
    
    vector<pair<string, vector<int>>> v(um.begin(), um.end());
    sort(v.begin(), v.end()); // num 기준 오름차순
    
    int f0 = fees[0], f1 = fees[1], f2 = fees[2], f3 = fees[3];
    for(auto& [num, time]: v){
        // 시간 계산
        double total = 0;
        for(int i = 0; i < time.size() - 1; i += 2){
            total += (time[i + 1] - time[i]);
        }
        
        // 요금 계산
        if(total <= f0){
            answer.push_back(f1);
        }
        else{
            answer.push_back(f1 + f3 * ceil((total - f0) / f2));
        }
    }
    return answer;
}