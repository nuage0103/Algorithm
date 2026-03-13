#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    /*
    R로만 이루어짐
    빈문자열 안됨
    K + 조건 만족하는 문자열 + K
    (K)(R)(K), R 1개 이상, K 양쪽 대칭
    */

    vector<int> prefix_k(n), prefix_r(n);
    if(s[0] == 'K') prefix_k[0] = 1;
    else prefix_r[0] = 1;
    for(int i = 1; i < n; i++){
        prefix_k[i] = prefix_k[i - 1];
        prefix_r[i] = prefix_r[i - 1];

        if(s[i] == 'K') prefix_k[i]++;
        else prefix_r[i]++;
    }

    int st = 0, en = n - 1;
    int max_len = -1;
    while(st <= en){
        int l_k = (st)? prefix_k[st - 1] : 0; // ~ st-1
        int r = (st)? prefix_r[en] - prefix_r[st - 1] : prefix_r[en]; // st ~ en
        int r_k = prefix_k[n - 1] - prefix_k[en]; // en+1 ~

        if(r >= 1) max_len = max(max_len, 2 * min(l_k, r_k) + r);

        while(st < n && s[st] != 'K') st++;
        st++;
        while(en >= 0 && s[en] != 'K') en--;
        en--;

        if(st > en) break;
    }
    if(max_len != -1) cout << max_len << '\n';
    else cout << "0\n";

    return 0;
}
