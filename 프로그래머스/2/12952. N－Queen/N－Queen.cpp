#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> row; // row[i] = j: (i, j)에 위치
int res;

void dfs(int depth, int n){
    if(depth == n){
        res++;
        return;
    }
    
    for(int j = 0; j < n; j++){
        bool pass = true;
        // (depth, j)
        for(int i = 0; i < depth; i++){
            // 열
            if(row[i] == j){
                pass = false;
                break;
            }
            // 대각선
            if(abs(depth - i) == abs(j - row[i])){
                pass = false;
                break;
            }
        }
        
        if(pass){
            row[depth] = j;
            dfs(depth + 1, n);
        }
    }
    
}

int solution(int n) {
    int answer = 0;

    row.resize(n, -1);
    res = 0;
    dfs(0, n);
    answer = res;
    
    return answer;
}