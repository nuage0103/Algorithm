#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    stack<int> st;
    int cnt = 0;
    for(int i = 0; i < n + 1; i++){
        int x, y;
        if(i < n) cin >> x >> y;
        else y = 0;

        while(!st.empty() && st.top() > y){
            int tmp = st.top();
            while(!st.empty() && st.top() == tmp) st.pop();
            cnt++;
        }
        st.push(y);
    }

    cout << cnt << '\n';

    return 0;
}
