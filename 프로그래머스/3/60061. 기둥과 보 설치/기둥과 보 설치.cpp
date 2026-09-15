#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check_ver(int x, int y, vector<vector<int>>& ver, vector<vector<int>>& hor, int n){    
    if(y == 0) return true;
    if(y - 1 >= 0 && ver[x][y - 1]) return true;
    if(hor[x][y]) return true;
    if(x - 1 >= 0 && hor[x - 1][y]) return true;
    
    return false;
}

bool check_hor(int x, int y, vector<vector<int>>& ver, vector<vector<int>>& hor, int n){    
    if(y - 1 >= 0 && ver[x][y - 1]) return true;
    if(x + 1 <= n && y - 1 >= 0 && ver[x + 1][y - 1]) return true;
    if((x - 1 >= 0 && hor[x - 1][y]) && (x + 1 <= n && hor[x + 1][y])) return true;
    
    return false;
}

bool check_all(vector<vector<int>>& ver, vector<vector<int>>& hor, int n){
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++){
            if(ver[i][j] && !check_ver(i, j, ver, hor, n)) return false;
            if(hor[i][j] && !check_hor(i, j, ver, hor, n)) return false;
        }
    }
    
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    vector<vector<int>> ver(n + 1, vector<int>(n + 1, 0)); // 기둥
    vector<vector<int>> hor(n + 1, vector<int>(n + 1, 0)); // 보
    for(auto& bf: build_frame){
        int x = bf[0];
        int y = bf[1];
        int type = bf[2]; // 0기둥, 1보
        int op = bf[3]; // 0삭제, 1설치
        if(type == 0){
            // 기둥
            if(op == 0){
                ver[x][y] = 0;
                if(!check_all(ver, hor, n)) ver[x][y] = 1;
            }
            else{
                if(check_ver(x, y, ver, hor, n)) ver[x][y] = 1;
            }
        }
        else{
            // 보. 바닥에 설치 요청 없음
            if(op == 0){
                hor[x][y] = 0;
                if(!check_all(ver, hor, n)) hor[x][y] = 1;
            }
            else{
                if(check_hor(x, y, ver, hor, n)) hor[x][y] = 1;
            }
        }
        
    }
    
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++){
            if(ver[i][j]) answer.push_back({i, j, 0});
            if(hor[i][j]) answer.push_back({i, j, 1});
        }
    }
    sort(answer.begin(), answer.end(), [](const auto& a, const auto& b){
        if(a[0] != b[0]) return a[0] < b[0];
        if(a[1] != b[1]) return a[1] < b[1];
        return a[2] < b[2];
    });
    return answer;
}