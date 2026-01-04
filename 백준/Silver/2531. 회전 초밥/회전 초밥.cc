#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, d, k, c; // 개수, 종류 개수, 연속k개, 쿠폰 번호(1~d)
    cin >> n >> d >> k >> c;
    vector<int> belt(n); // 1~d
    for(int i = 0; i < n; i++){
        cin >> belt[i];
    }

    vector<int> freq(d + 1, 0);
    int cnt = 0;
    // 초기 윈도우
    for(int i = 0; i < k; i++){
        int x = belt[i];
        if(!freq[x]) cnt++;
        freq[x]++;
    }
    // 연속k개 서로 다른 종류. +1(쿠폰)
    int max_cnt = (freq[c] == 0)? cnt + 1 : cnt;

    // 윈도우 이동
    for(int start = 1; start < n; start++){
        // 제거
        int x = belt[start - 1];
        freq[x]--;
        if(!freq[x]) cnt--;

        // 추가
        x = belt[(start + k - 1) % n];
        if(!freq[x]) cnt++;
        freq[x]++;

        // 쿠폰
        if(!freq[c]) max_cnt = max(max_cnt, cnt + 1);
        else max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt << '\n';

    return 0;
}
