#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> diff(n + 1, vector<int>(m + 1, 0));
    for(auto sk: skill){
        int type = sk[0];
        int r1 = sk[1], c1 = sk[2];
        int r2 = sk[3], c2 = sk[4];
        int deg = sk[5];
        if(type == 1) deg *= -1;
        
        diff[r1][c1] += deg;
        diff[r1][c2 + 1] -= deg;
        diff[r2 + 1][c1] -= deg;
        diff[r2 + 1][c2 + 1] += deg;
    }
    
    for(int i = 0; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            diff[i][j] += diff[i][j - 1];
        }
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 0; j < m + 1; j++){
            diff[i][j] += diff[i - 1][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            board[i][j] += diff[i][j];
            if(board[i][j] > 0) answer++;
        }
    }
    
    return answer;
}