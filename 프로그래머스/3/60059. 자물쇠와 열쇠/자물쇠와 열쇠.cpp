#include <string>
#include <vector>
#include <iostream>

using namespace std;

void rotate(vector<vector<int>>& key, int m){
    vector<vector<int>> tmp(m, vector<int>(m));
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            // (i, j) -> (j, m - 1 - i)
            tmp[j][m - 1 - i] = key[i][j];
        }
    }
    
    key = tmp;
}

bool check(vector<vector<int>>& board, int st, int n){
    for(int i = st; i < st + n; i++){
        for(int j = st; j < st + n; j++){
            if(board[i][j] != 1) return false;
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    int n = lock.size();
    int m = key.size(); // m <= n

    // 0홈, 1돌기
    // 열쇠 돌기, 자물쇠 홈 일치 + 열쇠 돌기, 자물쇠 돌기 안만남 = 합 1 (0, 2x)
    // 열쇠 이동, 회전
    int len = n + 2 * (m - 1);
    int lock_st = m - 1;
    
    for(int r = 0; r < 4; r++){
        // 회전
        rotate(key, m);
        
        // 전체 보드 초기화: 자물쇠 채우기. 위치 고정
        vector<vector<int>> board(len, vector<int>(len, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                board[lock_st + i][lock_st + j] = lock[i][j];
            }
        }
        
        // 열쇠 이동
        for(int stx = 0; stx < m + n - 1; stx++){
            for(int sty = 0; sty < m + n - 1; sty++){
                // 보드 상 열쇠 시작 위치(stx, sty)
                for(int x = 0; x < m; x++){
                    for(int y = 0; y < m; y++){
                        board[stx + x][sty + y] += key[x][y];
                    }
                }
                
                if(check(board, lock_st, n)) return true;
                
                // 복원
                for(int x = 0; x < m; x++){
                    for(int y = 0; y < m; y++){
                        board[stx + x][sty + y] -= key[x][y];
                    }
                }
            }
        }
    }
    
    return answer;
}