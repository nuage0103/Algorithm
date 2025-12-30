#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> belt; // 내구도
vector<int> robot; // 존재여부 0없다, 1있다
int start_idx, end_idx;
int cnt;
int stage; // 결과 단계

// 회전: 올리는/내리는 위치 인덱스 변경
// 로봇 이동. 벨트에 올린 순서대로: 내리는 위치 인덱스부터 확인
// 로봇 올리기
void rotate_belt(){
    start_idx = (start_idx)? (start_idx - 1) : (2 * n - 1);
    end_idx = (end_idx)? (end_idx - 1) : (2 * n - 1);

    robot[end_idx] = 0;
}

void move_robot(){
    int cur = end_idx; // 먼저 벨트에 올라간 로봇부터 이동
    int next;
    for(int i = 0; i < n - 1; i++){
        next = cur;
        cur = (cur)? (cur - 1) : (2 * n - 1);
        if(belt[next] && !robot[next] && robot[cur]){
            belt[next]--;
            if(!belt[next]) cnt++;

            robot[next] = 1;
            robot[cur] = 0;
        }
    }

    robot[end_idx] = 0;
}

void put_robot(){
    if(belt[start_idx] && !robot[start_idx]){
        belt[start_idx]--;
        if(!belt[start_idx]) cnt++;

        robot[start_idx] = 1;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> k;

    belt.resize(2*n);
    robot.resize(2*n, 0);
    for(int i = 0; i < 2*n; i++){
        cin >> belt[i];
    }

    stage = 0;
    cnt = 0;
    start_idx = 0;
    end_idx = n-1;
    while(cnt < k){
        stage++;
        rotate_belt();
        move_robot();
        put_robot();
    }
    cout << stage << '\n';

    return 0;
}
