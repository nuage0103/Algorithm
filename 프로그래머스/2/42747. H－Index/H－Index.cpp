#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    // citations[i]: 논문i가 인용된 횟수
    sort(citations.begin(), citations.end());
    int n = citations.size();
    
    int answer = 0; // 최대 h
    for(int i=0; i<n; i++){
        int h = n - i; // 논문i ~ n-1 포함한 개수
        
        // h번 이상 인용
        // c[i] < h: c[i]는 포함 안됨. 조건 충족 못함
        if(citations[i] >= h) {
            answer = h;
            break;
        }
    }
    return answer;
}