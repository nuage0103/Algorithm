#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

string n;
int k, m;
int res = 0;

int cal(string s){
    int sum = 0;
    for(int i = 0; i < m; i++){
        sum = sum * 10 + (s[i] - '0');
    }

    return sum;
}

bool bfs(){
    int cnt = 0;
    queue<string> q;
    q.push(n);

    while(!q.empty() && cnt < k){
        set<string> visited; // 현재 단계에서 중복 제외. 각 단계는 독립적
        int size = q.size(); // 각 단계별로 모든 경우의수 고려

        while(size--){
            string cur = q.front();
            q.pop();

            for(int i = 0; i < m - 1; i++){
                for(int j = i + 1; j < m; j++){
                    if(i == 0 && cur[j] == '0') continue;

                    swap(cur[i], cur[j]);
                    if(visited.find(cur) == visited.end()){
                        if(cnt == k-1){
                            res = max(res, cal(cur));
                        }
                        q.push(cur);
                        visited.insert(cur);
                    }
                    swap(cur[i], cur[j]);
                }
            }
        }

        cnt++;
    }

    return (cnt == k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    m = n.length();

    if(m == 1 || (m == 2 && n[m-1] == '0')){
        printf("-1\n");
        return 0;
    }

    if(bfs()) printf("%d\n",res);
    else printf("-1\n");

    return 0;
}
