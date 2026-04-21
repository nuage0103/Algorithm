#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> gi; // 기둥
vector<vector<int>> bo; // 보

bool check(int n, int x, int y, int a){
    if(a == 0){
        if(y == 0) return true;
        if(y - 1 >= 0 && gi[x][y - 1]) return true;
        if(x - 1 >= 0 && bo[x - 1][y]) return true;
        if(bo[x][y]) return true;
    }
    if(a == 1){
        if(y - 1 >= 0 && gi[x][y - 1]) return true;
        if(x + 1 <= n && y - 1 >= 0 && gi[x + 1][y - 1]) return true;
        if((x - 1 >= 0 && bo[x - 1][y]) && (x + 1 <= n && bo[x + 1][y])) return true;
    }
    
    return false;
}

bool del_check(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(gi[i][j] && !check(n, i, j, 0)) return false;
            if(bo[i][j] && !check(n, i, j, 1)) return false;
        }
    }
    
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    gi.resize(n + 2, vector<int>(n + 2, 0));
    bo.resize(n + 2, vector<int>(n + 2, 0));
    for(auto& f: build_frame){
        int x = f[0], y = f[1], a = f[2], b = f[3];
        if(a == 0){ // 기둥
            if(b == 0){
                // 삭제: 일단 삭제하고, 다른 구조물들의 조건 확인 후 복원 여부 결정
                gi[x][y] = 0;
                if(!del_check(n)) gi[x][y] = 1;
            }
            if(b == 1){
                // 설치
                if(check(n, x, y, a)) gi[x][y] = 1;
            }
        }
        
        if(a == 1){ // 보
            if(b == 0){
                // 삭제
                bo[x][y] = 0;
                if(!del_check(n)) bo[x][y] = 1;
            }
            if(b == 1){
                // 설치
                if(check(n, x, y, a)) bo[x][y] = 1;
            }
        }
    }
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            // 동일 좌표: 기둥이 보보다 앞에
            if(gi[i][j]) answer.push_back({i, j, 0});
            if(bo[i][j]) answer.push_back({i, j, 1});
        }
    }
    return answer;
}