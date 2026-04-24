#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    int n = citations.size();
    sort(citations.begin(), citations.end());
    
    for(int i = n - 1; i >= 0; i--){
        int h = n - i; // i ~ n-1 개수
        if(citations[i] >= h){
            answer = h;
        }
    }
    
    return answer;
}