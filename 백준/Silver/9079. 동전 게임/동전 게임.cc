#include<bits/stdc++.h>
using namespace std;

/*
111000000 448
000111000 56
000000111 7
100100100 292
010010010 146
001001001 73
100010001 273
001010100 84
*/

int solve(int bit){
    int d[8] = {448, 56, 7, 292, 146, 73, 273, 84};
    vector<int> visited(1<<9);
    queue<pair<int, int>> q; // {bit, cnt}
    q.push({bit, 0});
    visited[bit] = 1;
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int next = cur ^ d[i];
            if(next == 0 || next == (1<<9)-1){
                return cnt + 1;
            }
            if(visited[next]) continue;

            visited[next] = 1;
            q.push({next, cnt + 1});
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string inp = "";
        for(int i=0; i<3; i++){
            string tmp;
            getline(cin, tmp);
            for(int j=0; j<5; j+=2){
                inp += tmp[j];
            }
        }

        int bit = 0;
        for(int i=0; i<9; i++){
            bit = bit << 1;
            if(inp[i] == 'H') bit |= 1;
        }

        if(bit == 0 || bit == (1<<9)-1) cout << 0 << '\n';
        else cout << solve(bit) << '\n';
    }

    return 0;
}
