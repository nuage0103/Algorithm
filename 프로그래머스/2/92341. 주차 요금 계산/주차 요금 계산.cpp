#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

/*
1. key값 정렬이 필요한지
o: map
x: Q2

2. key 타입이 pair / vector
o: map
x: unordered_map
*/

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer; // id 오름차순
    
    map<string, vector<int>> id_time; // {id, time vec}
    
    for(auto& r: records){
        stringstream ss(r);
        string h, m, id;
        string r2;
        getline(ss, h, ':');
        getline(ss, r2, ':');
        stringstream ss2(r2);
        ss2 >> m >> id;
                
        int hr = stoi(h);
        int min = stoi(m);
        id_time[id].push_back(hr * 60 + min);
    }
    for(auto& [k, v]: id_time){
        if(v.size() % 2) v.push_back(23 * 60 + 59);
    }
    
    // 기본 시간, 기본 요금, 단위 시간, 단위 요금
    int f0 = fees[0], f1 = fees[1], f2 = fees[2], f3 = fees[3];
    for(auto& [k, v]: id_time){
        // 누적 시간
        int total = 0;
        for(int i = 0; i < v.size() - 1; i += 2){
            total += v[i + 1] - v[i];
        }

        if(total <= f0) answer.push_back(f1);
        else{
            answer.push_back(f1 + ceil((total - f0) / (float)f2) * f3);
        }
    }
    
    return answer;
}










