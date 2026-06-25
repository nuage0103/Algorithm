#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt;

void dfs(int depth, int sum, vector<int>& numbers, int target){
    if(depth == numbers.size()){
        if(sum == target) cnt++;
        return;
    }
    
    dfs(depth + 1, sum + numbers[depth], numbers, target);
    dfs(depth + 1, sum - numbers[depth], numbers, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    cnt = 0;
    dfs(0, 0, numbers, target);
    
    answer = cnt;
    return answer;
}