#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int min_move = len - 1; // 오른쪽으로만 이동
    for(int i=0; i<len; i++){
        // 상하
        int n = name[i] - 'A';
        if(n < 13) answer += n;
        else answer += (26 - n);
        
        // 좌우
        int next = i+1; // A가 아닌 다음 문자
        while(name[next] == 'A') next++;
        min_move = min({min_move, 2*i + len - next, 2*(len - next) + i});
    }
    answer += min_move;
    return answer;
}