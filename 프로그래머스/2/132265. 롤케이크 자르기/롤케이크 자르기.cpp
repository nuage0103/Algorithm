#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = -1;
    int n = topping.size();
    unordered_map<int, int> l_freq, r_freq;
    int left = 0, right = 0; // 0~i, i+1~n-1
    for(int i = 0; i < n; i++){
        // right 0~n-1
        r_freq[topping[i]]++;
        if(r_freq[topping[i]] == 1) right++;
    }
    answer = 0;
    for(int i = 0; i < n - 1; i++){
        l_freq[topping[i]]++;
        if(l_freq[topping[i]] == 1) left++;
        
        r_freq[topping[i]]--;
        if(r_freq[topping[i]] == 0) right--;
        
        if(left == right) answer++;
    }
    return answer;
}