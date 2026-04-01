#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    stack<pair<int, int>> st; // {높이, 인덱스}
    vector<int> res(n); // {수신 인덱스}
    for(int i = 0; i < n; i++){
        int cur;
        cin >> cur;

        while(!st.empty() && st.top().first < cur) st.pop();
        if(!st.empty()) res[i] = st.top().second;

        st.push({cur, i + 1}); // 인덱스 1base
    }

    for(auto x: res) cout << x << ' ';
    cout << '\n';

    return 0;
}
