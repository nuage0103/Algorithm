#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int k;
vector<char> inp;
string min_num, max_num;
int visited[10];
vector<int> res;

void dfs(int depth){
    if(depth == k + 1){
        string sum = "";
        for(int i = 0; i <= k; i++){
            sum += (res[i] + '0');
        }
        if(min_num.empty() || min_num > sum){
            min_num = sum;
        }
        if(max_num.empty() || max_num < sum){
            max_num = sum;
        }
        return;
    }

    for(int i = 0; i < 10; i++){
        if(visited[i]) continue;

        if(depth > 0){
            if(inp[depth - 1] == '<' && res[depth - 1] >= i) continue;
            if(inp[depth - 1] == '>' && res[depth - 1] <= i) continue;
        }

        visited[i] = 1;
        res[depth] = i;
        dfs(depth + 1);
        visited[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    inp.resize(k);
    for(int i = 0; i < k; i++){
        cin >> inp[i];
    }

    max_num = "";
    min_num = "";
    res.resize(k + 1);
    dfs(0);
    cout << max_num << '\n' << min_num << '\n';

    return 0;
}
