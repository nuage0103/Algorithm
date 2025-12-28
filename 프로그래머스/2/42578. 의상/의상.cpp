#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) { // {이름, 종류}
    unordered_map<string, int> map; // {종류, 이름 개수}. 이름 중복 없음
    int n = clothes.size();
    for(int i=0; i<n; i++){
        string type = clothes[i][1];
        if(map.find(type) == map.end()) map[type] = 1;
        else map[type]++;
    }
    
    int answer = 1;
    for(auto& it: map){
        // 개수 + 아무것도 선택안함(1)
        answer *= (it.second + 1);
    }
    answer -= 1;
    return answer;
}