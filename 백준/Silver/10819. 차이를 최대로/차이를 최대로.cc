#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> a;
vector<int> visited;
vector<int> new_a;
int res;

void dfs(int depth){
    if(depth == n){
        int sum = 0;
        for(int i = 0; i < n - 1; i++){
            sum += abs(new_a[i] - new_a[i + 1]);
        }
        res = max(res, sum);
        return;
    }

    for(int i = 0; i < n; i++){
        if(visited[i]) continue;

        visited[i] = 1;
        new_a[depth] = a[i];
        dfs(depth + 1);
        visited[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    visited.resize(n);
    new_a.resize(n);
    res = -1;
    dfs(0);
    cout << res << '\n';

    return 0;
}
