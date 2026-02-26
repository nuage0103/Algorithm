#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    vector<string> sig(5);
    int pos = 0;
    for(int i = 0; i < 5; i++){
        sig[i] = s.substr(pos, n / 5);
        pos += n / 5;
    }

    vector<vector<string>> num(10);
    num[0] = {"###", "#.#", "#.#", "#.#", "###"};
    num[1] = {"#", "#", "#", "#", "#"};
    num[2] = {"###", "..#", "###", "#..", "###"};
    num[3] = {"###", "..#", "###", "..#", "###"};
    num[4] = {"#.#", "#.#", "###", "..#", "..#"};
    num[5] = {"###", "#..", "###", "..#", "###"};
    num[6] = {"###", "#..", "###", "#.#", "###"};
    num[7] = {"###", "..#", "..#", "..#", "..#"};
    num[8] = {"###", "#.#", "###", "#.#", "###"};
    num[9] = {"###", "#.#", "###", "..#", "###"};

    int c = 0;
    int len = sig[0].length();
    while(c < len){
        while(c < len && sig[0][c] == '.') c++;
        if(c == len) break;

        bool one = true;
        if(c + 1 < len){
            for(int r = 0; r < 5; r++){
                if(sig[r][c + 1] == '#'){
                    one = false;
                    break;
                }
            }
        }
        if(one){
            cout << 1;
            c++;
            continue;
        }

        vector<string> cur(5);
        for(int r = 0; r < 5; r++){
            cur[r] = sig[r].substr(c, 3);
        }

        for(int i = 0; i < 10; i++){
            if(i == 1) continue;
            if(cur == num[i]) {
                cout << i;
                break;
            }
        }

        c += 3;
    }
    cout << '\n';

    return 0;
}
