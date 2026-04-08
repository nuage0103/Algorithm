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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    stack<int> st;
    vector<int> nge(n, -1);
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && st.top() <= a[i]) st.pop();
        if(!st.empty()) nge[i] = st.top();
        st.push(a[i]);
    }
    for(int x: nge) cout << x << ' ';
    cout << '\n';

    return 0;
}
