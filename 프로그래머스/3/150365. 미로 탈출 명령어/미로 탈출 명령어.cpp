#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int dist = abs(x - r) + abs(y - c);
    // 남은 거리 <= k
    // 남은 거리 > k: 차이 만큼 왕복(짝수 거리)
    if(dist > k || abs(dist - k) % 2 != 0) return "impossible";
    
    // 0-base
    x--, y--, r--, c--;
    
    // 사전순: d, l, r, u
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    char op[4] = {'d', 'l', 'r', 'u'};
    while(k--){
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            dist = abs(nx - r) + abs(ny - c);
            if(dist > k || abs(dist - k) % 2 != 0) continue;
            
            x = nx;
            y = ny;
            answer += op[i];
            break;
        }
    }
    
    return answer;
}
