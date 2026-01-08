#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> ans;

void dfs(int depth, int sum, int last, string s){
    if(depth == n){
        if(sum == 0) ans.push_back(s);
        return;
    }

    int x = depth + 1;
    // +-
    dfs(x, sum + x, x, s + "+" + to_string(x));
    dfs(x, sum - x, -x, s + "-" + to_string(x));

    // 공백
    int new_last;
    if(last >= 0) new_last = last * 10 + x;
    else new_last = last * 10 - x;
    dfs(x, sum - last + new_last, new_last, s + " " + to_string(x));

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ans.clear();

        dfs(1, 1, 1, "1");

        sort(ans.begin(), ans.end());
        for(auto x: ans) cout << x << '\n';
        cout << '\n';
    }

    return 0;
}
