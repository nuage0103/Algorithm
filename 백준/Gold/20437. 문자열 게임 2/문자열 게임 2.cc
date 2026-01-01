#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*

*/

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        string w;
        int k;
        cin >> w >> k;
        int len = w.length();

        vector<vector<int>> alpha; // alpha[i] = i번째 알파벳이 쓰인 인덱스
        alpha.resize(26);
        for(int i = 0; i < len; i++){
            alpha[w[i] - 'a'].push_back(i);
        }

        int min_len = 100000;
        int max_len = 0;
        for(int i = 0; i < 26; i++){
            if(alpha[i].size() < k) continue;

            // k번 쓰고, 가장짧: 첫번째, 마지막 문자가 해당 문자
            // x----x인 가장 짧은, 긴 연속 문자열 길이
            int last = (int)alpha[i].size();
            for(int j = 0; j <= last - k; j++){
                min_len = min(min_len, alpha[i][j + k - 1] - alpha[i][j] + 1);
                max_len = max(max_len, alpha[i][j + k - 1] - alpha[i][j] + 1);
            }
        }

        if(min_len == 100000) cout << "-1\n";
        else cout << min_len << ' ' << max_len << '\n';
    }

    return 0;
}
