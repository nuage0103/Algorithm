#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

/*
1. 단순케이스
- 문제 예제처럼 정상적인 흐름 확인 용도
- 코드 뼈대 잡는 용

2. 히든케이스
- 예외적 상황, 극단값 위주

3. 최대케이스
- 문제에서 허용하는 가장 큰 입력값
- 시간 초과 여부 확인 용도
- 시간복잡도 계산

4. 경계값 테스트
- 입력 범위의 최소값, 최대값

5. 엣지케이스
- 예상치 못한 입력 받은 경우에 대해 동작 테스트
- ex: 빈 배열, 모든 값이 동일한 배열, 첫번째 요소만 검사, null

*/

typedef pair<int, int> pii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> h(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }

    vector<pii> res(n + 1); // {개수, 가장 인접 번호}

    // 오른쪽 (왼 <- 오 순회)
    stack<pii> right; // {높이, 번호}
    right.push({h[n], n});
    for(int i = n - 1; i > 0; i--){
        // 인접 오른쪽 건물과 비교
        // 내가 더 작으면 스택 구성 동일
        // 내가 더 크거나 같으면 나보다 작은거 스택에서 제거
        if(h[i] >= h[i + 1]){
            while(!right.empty() && right.top().first <= h[i]) right.pop();
        }

        // 스택 탑 = 가장 가까이 보이는 건물
        res[i].first += right.size();
        if(!right.empty()) res[i].second = right.top().second;

        // 나도 스택에 삽입
        right.push({h[i], i});
    }

    // 왼쪽
    stack<pii> left; // {높이, 번호}
    left.push({h[1], 1});
    for(int i = 2; i <= n; i++){
        if(h[i] >= h[i - 1]){
            while(!left.empty() && left.top().first <= h[i]) left.pop();
        }

        res[i].first += left.size();
        if(!left.empty()) {
            //res[i].second = left.top().second;
            int l = left.top().second;
            int r = res[i].second;

            if(abs(l - i) == abs(r - i)) res[i].second = l;
            else res[i].second = (abs(l - i) < abs(r - i))? l : r;
        }

        left.push({h[i], i});
    }

    for(int i = 1; i <= n; i++){
        if(res[i].first == 0) cout << "0\n";
        else cout << res[i].first << ' ' << res[i].second << '\n';
    }

    return 0;
}
