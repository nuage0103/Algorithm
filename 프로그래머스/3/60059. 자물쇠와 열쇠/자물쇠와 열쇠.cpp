#include <string>
#include <vector>
#include <iostream>

using namespace std;

void rotate(vector<vector<int>>& key, int m){
    vector<vector<int>> ret(m, vector<int>(m));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            ret[j][m - 1 - i] = key[i][j];
        }
    }
    key = ret;
}

bool check(const vector<vector<int>>& board, int st, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[st + i][st + j] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    int m = key.size();
    int n = lock.size();
    int len = n + 2 * (m - 1);
    int lock_st = m - 1;
    vector<vector<int>> board;
    // 열쇠돌기+자물쇠홈=1
    for(int T = 0; T < 4; T++){
        board.assign(len, vector<int>(len, 0));
        
        // board += lock
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                board[lock_st + i][lock_st + j] = lock[i][j];
            }
        }
        
        for(int st_x = 0; st_x < n + m - 1; st_x++){
            for(int st_y = 0; st_y < n + m - 1; st_y++){
                // board += key
                for(int i = 0; i < m; i++){
                    for(int j = 0; j < m; j++){
                        board[st_x + i][st_y + j] += key[i][j];
                    }
                }
                // check
                if(check(board, lock_st, n)) return true;
                
                // board -= key
                for(int i = 0; i < m; i++){
                    for(int j = 0; j < m; j++){
                        board[st_x + i][st_y + j] -= key[i][j];
                    }
                }
            }
        }
        
        rotate(key, m);
    }
    
    //return answer;
    return false;
}