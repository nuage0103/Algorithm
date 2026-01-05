#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pii> cal;
    int freq[367] = {0};
    int s, e;
    for(int i=0; i<n; i++){
        cin >> s >> e;
        cal.push_back({s, e});
        for(int i = s; i <= e; i++) freq[i]++;
    }

    sort(cal.begin(), cal.end(), [](pii& a, pii& b){
        // 시작이 빠른
        if(a.first != b.first) return a.first < b.first;
        // 기간이 긴: 나중에 끝남
        else return a.second > b.second;
    });

    int start = cal[0].first;
    int end = cal[n-1].second;
    int res = 0;
    while(start <= end){
        if(!freq[start]){
            start++;
            continue;
        }

        int width = 0;
        int height = -1e9;
        while(freq[start]){
            width++;
            height = max(height, freq[start]);
            start++;
        }
        res += width * height;
        width = 0;
        height = -1e9;
    }

    cout << res << '\n';

    return 0;
}
