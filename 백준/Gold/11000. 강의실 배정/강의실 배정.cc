#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> time(n);
    for(int i = 0; i < n; i++){
        int s, t;
        cin >> s >> t;
        time[i] = {s, t};
    }
    sort(time.begin(), time.end()); // 시작 시간 오름차순

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(time[0].second);
    //int res = pq.size();
    for(int i = 1; i < n; i++){
        if(pq.top() <= time[i].first) pq.pop();

        pq.push(time[i].second);
        //res = max(res, (int)pq.size());
    }
    cout << pq.size() << '\n'; // 크기 유지 또는 증가

    return 0;
}
