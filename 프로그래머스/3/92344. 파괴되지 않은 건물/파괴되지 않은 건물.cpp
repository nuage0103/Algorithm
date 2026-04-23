#include <string>
#include <vector>

using namespace std;

/*
0 이하면 파괴. 내구도 계속 감소 가능, 복구도 가능

skill
적은 -, 아군은 +로 누적합

마지막에 board랑 합산하면서 0 초과인 경우 집계
*/

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0)); // sum[i][j] = (0, 0) ~ (i, j) 구간합
    for(auto sk: skill){
        int r1 = sk[1], c1 = sk[2];
        int r2 = sk[3], c2 = sk[4];
        int d = sk[5];
        if(sk[0] == 1) d *= -1;
        
        // 구간 지정
        sum[r1][c1] += d;
        sum[r1][c2 + 1] -= d;
        sum[r2 + 1][c1] -= d;
        sum[r2 + 1][c2 + 1] += d;
    }
    // 가로 누적합
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            sum[i][j] += sum[i][j - 1]; 
        }
    }
    
    // 세로 누적합
    for(int j = 0; j < m; j++){
        for(int i = 1; i < n; i++){
            sum[i][j] += sum[i - 1][j]; 
        }
    }
    
    // 내구도와 합산, answer 집계
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] + sum[i][j] > 0) answer++;
        }
    }
    return answer;
}