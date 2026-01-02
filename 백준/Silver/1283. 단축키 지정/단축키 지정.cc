#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    vector<vector<string>> inp(n);
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);

        int pos = -1;
        int prev = 0;
        while(1){
            pos = s.find(' ', prev);
            if(pos == string::npos) {
                inp[i].push_back(s.substr(prev));
                break;
            }

            inp[i].push_back(s.substr(prev, pos - prev));
            prev = pos + 1;
        }
    }

    // 대소문자 구분없음. A=a
    int alpha[26] = {0};
    for(int i = 0; i < n; i++){
        int cnt = (int)inp[i].size();

        bool check = false;
        for(int j = 0; j < cnt; j++){
            char first = inp[i][j][0]; // 단어의 첫글자
            int idx = ('A' <= first && first <= 'Z')? first - 'A' : first - 'a';
            if(!alpha[idx]){
                string tmp = inp[i][j];
                inp[i][j] = "[" + tmp.substr(0, 1) + "]" + tmp.substr(1);
                alpha[idx] = 1;
                check = true;
                break;
            }
        }

        if(check) continue;

        for(int j = 0; j < cnt; j++){
            if(check) break;

            string str = inp[i][j];
            for(int k = 1; k < str.length(); k++){ // 첫글자 제외
                char c = str[k];
                int idx = ('A' <= c && c <= 'Z')? c - 'A' : c - 'a';
                if(!alpha[idx]){
                    inp[i][j] = str.substr(0, k) + "[" + str.substr(k, 1) + "]" + str.substr(k + 1);
                    alpha[idx] = 1;
                    check = true;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(auto x: inp[i]) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
