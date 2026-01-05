#include <iostream>
using namespace std;

bool winner(const char map[3][3], char c){
    for(int i = 0; i < 3; i++){
        // 가로
        if(map[i][0] == c){
            if(map[i][0] == map[i][1] && map[i][0] == map[i][2]) return true;
        }
        // 세로
        if(map[0][i] == c){
            if(map[0][i] == map[1][i] && map[0][i] == map[2][i]) return true;
        }
    }

    // 대각
    if(map[1][1] == c){
        if(map[1][1] == map[0][0] && map[1][1] == map[2][2]) return true;
        if(map[1][1] == map[0][2] && map[1][1] == map[2][0]) return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1){
        string s;
        cin >> s;
        if(s == "end") break;

        char map[3][3];
        int cnt_x = 0, cnt_o = 0;
        for(int i = 0; i < 9; i++){
            map[i/3][i%3] = s[i];
            if(s[i] == 'X') cnt_x++;
            if(s[i] == 'O') cnt_o++;
        }

        bool win_x = winner(map, 'X');
        bool win_o = winner(map, 'O');

        if(win_x && !win_o && cnt_x == cnt_o + 1) cout << "valid\n";
        else if(!win_x && win_o && cnt_x == cnt_o) cout << "valid\n";
        else if(!win_x && !win_o && cnt_x == 5 && cnt_o == 4) cout << "valid\n";
        else cout << "invalid\n";
    }

    return 0;
}
