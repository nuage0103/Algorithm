#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

void remove1(int n, int m, vector<string>& storage, char c){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<pair<int, int>> removed;
    
    for(int i = 0; i < n; i++){
        if(storage[i][0] == c) removed.insert({i, 0});
        if(storage[i][0] == '-') q.push({i, 0});
        if(storage[i][m - 1] == c) removed.insert({i, m - 1});
        if(storage[i][m - 1] == '-') q.push({i, m - 1});
    }
    for(int j = 0; j < m; j++){
        if(storage[0][j] == c) removed.insert({0, j});
        if(storage[0][j] == '-') q.push({0, j});
        if(storage[n - 1][j] == c) removed.insert({n - 1, j});
        if(storage[n - 1][j] == '-') q.push({n - 1, j});
    }
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        
        if(storage[x][y] == c){
            removed.insert({x, y});
            continue;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny]) continue;
            if(storage[nx][ny] != c && storage[nx][ny] != '-') continue;
            
            q.push({nx, ny});
            visited[nx][ny] = 1;
            
        }
    }
    
    for(auto& [x, y]: removed){
        storage[x][y] = '-';
    }
    
}

void remove2(int n, int m, vector<string>& storage, char c){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(storage[i][j] == c){
                storage[i][j] = '-';
            }
        }
    }

}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    int n = storage.size();
    int m = storage[0].size();
    
    for(int i = 0; i < requests.size(); i++){
        if(requests[i].size() == 1) remove1(n, m, storage, requests[i][0]);
        else remove2(n, m, storage, requests[i][0]);
    }
    
    answer = n * m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(storage[i][j] == '-') answer--;
        }
    }
    
    return answer;
}