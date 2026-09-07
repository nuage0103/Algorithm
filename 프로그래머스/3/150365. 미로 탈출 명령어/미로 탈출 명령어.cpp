#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    int dist = abs(x - r) + abs(y - c);
    if(dist > k || (k - dist) % 2 != 0) return "impossible";
    
    int dx[4] = {1, 0, 0, -1}; // 알파벳순
    int dy[4] = {0, -1, 1, 0};
    string op = "dlru";
    
    int curx = x - 1, cury = y - 1;
    r--; c--;
    while(k--){
        for(int i = 0; i < 4; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int dist = abs(nx - r) + abs(ny - c);
            if(dist > k || (k - dist) % 2 != 0) continue;
            
            curx = nx;
            cury = ny;
            answer += op[i];
            break;
        }
    }
    if(curx != r || cury != c) answer = "impossible";
    
    return answer;
}