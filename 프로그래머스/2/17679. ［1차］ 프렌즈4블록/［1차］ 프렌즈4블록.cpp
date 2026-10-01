#include <string>
#include <vector>
#include <iostream>

using namespace std;

void remove(int m, int n, vector<string>& board, const vector<vector<bool>>& rm){
    for(int j = 0; j < n; j++){
        int idx = m - 1;
        for(int i = m - 1; i >= 0; i--){
            if(!rm[i][j]){
                board[idx][j] = board[i][j];
                idx--;
            }
        }
        
        while(idx >= 0){
            board[idx][j] = '-';
            idx--;
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1){
        // 탐색지점: 좌상(x,y)
        vector<vector<bool>> rm(m, vector<bool>(n, false));
        bool changed = false;
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n - 1; j++){
                char c = board[i][j];
                if(c == '-') continue;
                
                if(c == board[i][j + 1] && c == board[i + 1][j] && c == board[i + 1][j + 1]){
                    rm[i][j] = true;
                    rm[i][j + 1] = true;
                    rm[i + 1][j] = true;
                    rm[i + 1][j + 1] = true;
                    changed = true;
                }
            }
        }
        if(!changed) break;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rm[i][j]) answer++;
            }
        }
        // 제거
        remove(m, n, board, rm);
    }
    
    return answer;
}