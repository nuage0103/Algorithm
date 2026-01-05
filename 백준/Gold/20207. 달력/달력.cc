#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
/*
index tree(segment tree): update와 query 계속 발생, 중간에 발생하는 query에 대한 응답처리 가능
difference array: 마지막에 몰아서 update, query(최종값. 누적합)
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pii> cal;
    int diff[367] = {0};
    for(int i=0; i<n; i++){
        int s, e;
        cin >> s >> e;
        cal.push_back({s, e});
        diff[s]++;
        diff[e + 1]--;
    }

    sort(cal.begin(), cal.end(), [](pii& a, pii& b){
        // 시작이 빠른
        if(a.first != b.first) return a.first < b.first;
        // 기간이 긴: 나중에 끝남
        else return a.second > b.second;
    });

    int start = cal[0].first;
    int end = cal[n-1].second;
    for(int i = 1; i < 366; i++){
        diff[i + 1] += diff[i];
    }

    int res = 0;
    int width = 0;
    int height = -1e9;
    while(start <= end){
        if(!diff[start]) {
            start++;
            continue;
        }

        while(diff[start] > 0) {
            width++;
            height = max(height, diff[start]);
            start++;
        }
        res += width * height;
        width = 0;
        height = -1e9;
    }
    cout << res << '\n';

    return 0;
}
