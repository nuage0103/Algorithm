#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
[i][j] -> [i+1][j], [i+1][j+1]
*/

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
            
    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    
    answer = triangle[0][0];
    
    return answer;
}