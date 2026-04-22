#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = -1;
    
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    
    int idx = 0;
    answer = 0;
    int n = A.size();
    for(int i = 0; i < n; i++){
        if(A[i] < B[idx]){
            answer++;
            idx++;
        }
    }
    
    return answer;
}