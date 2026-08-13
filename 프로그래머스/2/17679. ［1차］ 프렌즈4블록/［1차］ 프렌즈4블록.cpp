#include <string>
#include <vector>
#include <iostream>

using namespace std;

// m개, 길이n 문자열

bool check(int x, int y, vector<string>& board, vector<vector<int>>& erase){
    int dx[3] = {0, 1, 1};
    int dy[3] = {1, 0, 1};
    
    char c = board[x][y];
    bool same = true;
    for(int i = 0; i < 3; i++){
        if(board[x + dx[i]][y + dy[i]] != c) {
            same = false;
            break;
        }
    }

    if(same) {
        for(int i = 0; i < 3; i++){
            erase[x + dx[i]][y + dy[i]] = 1;
        }
        erase[x][y] = 1;
    }
    
    return erase[x][y] == 1;
}

void move(int m, int n, vector<string>& board){
    for(int j = 0; j < n; j++){
        int p = m - 1; // 현재 맨밑 빈칸
        for(int i = m - 1; i >= 0; i--){
            if(board[i][j] != '0'){
                board[p][j] = board[i][j];
                if(p != i) board[i][j] = '0';
                p--;
            }
        }
        
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(1){
        bool flag = false;
        
        // 지울 블록 표시
        vector<vector<int>> erase(m, vector<int>(n));
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n - 1; j++){
                if(board[i][j] != '0'){
                    if(check(i, j, board, erase)) flag = true;
                }
            }
        }
        
        if(!flag) break;
        
        // 판 모두 확인 후 지우기
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(erase[i][j]){
                    board[i][j] = '0';
                    answer++;
                }
            }
        }

        move(m, n, board);
    }
    
    return answer;
}