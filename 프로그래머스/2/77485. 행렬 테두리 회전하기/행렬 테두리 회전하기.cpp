#include <string>
#include <vector>
#include <iostream>

using namespace std;

int move(int x1, int y1, int x2, int y2, vector<vector<int>>& board){
    // 우
    int tmp = board[x1][y2];
    int ret = tmp;
    for(int i = y2; i > y1; i--){
        board[x1][i] = board[x1][i - 1];
        ret = min(ret, board[x1][i]);
    }
    // 상
    for(int i = x1; i < x2; i++){
        board[i][y1] = board[i + 1][y1];
        ret = min(ret, board[i][y1]);
    }
    // 좌
    for(int i = y1; i < y2; i++){
        board[x2][i] = board[x2][i + 1];
        ret = min(ret, board[x2][i]);
    }
    // 하
    for(int i = x2; i > x1; i--){
        board[i][y2] = board[i - 1][y2];
        ret = min(ret, board[i][y2]);
    }
    board[x1 + 1][y2] = tmp;
    
    return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> board(rows, vector<int>(columns));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            board[i][j] = i * columns + (j + 1);
        }
    }
    
    // 테두리 한줄만 시계방향 한칸 회전
    // 위치 바뀐 최소원소
    for(auto& q: queries){
        int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
        answer.push_back(move(x1 - 1, y1 - 1, x2 - 1, y2 - 1, board));
    }
    return answer;
}