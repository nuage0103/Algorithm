#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n = prices.size();
    answer.resize(n);
    
    stack<pair<int, int>> st; // {price, idx}
    for(int i = 0; i < n; i++){
        int cur = prices[i];
        
        while(!st.empty() && st.top().first > cur){
            answer[st.top().second] = i - st.top().second;
            st.pop();
        }
        st.push({cur, i});
    }
    
    int idx = st.top().second;
    while(!st.empty()){
        answer[st.top().second] = idx - st.top().second;
        st.pop();
    }
    
    return answer;
}