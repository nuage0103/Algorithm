#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), 
        [](vector<int>& v1, vector<int>& v2){
            if(v1[1] != v2[1]) return v1[1] < v2[1];
            else return v1[0] < v2[0];
        });
    
    int answer = 0; // 미사일 개수
    
    int end = targets[0][1];
    answer++;
    for(int i=1; i<targets.size(); i++){
        if(targets[i][0] < end){
            //요격 성공
            continue;
        }
        else{
            //요격 실패. 범위 이동
            end = targets[i][1];
            answer++;
        }
    }
    return answer;
}