#include <stdio.h>
#include <stdlib.h>

int n, m;
int input[9];
int res[9];
//int visited[9];

int compare(const void* a, const void* b){
    if(*(int*)a > *(int*) b) return 1;
    else if(*(int*)a > *(int*) b) return -1;
    else return 0;
}

void dfs(int depth){
    if(depth == m){ // depth : 수열 길이(m)
        for(int i = 0; i < m; i++){
            printf("%d ", res[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 0; i < n; i++){
        if(input[i] >= res[depth -1]){
            res[depth] = input[i]; // 경로 기록(수열)
            dfs(depth + 1);      
        }

    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &input[i]);
    }
    qsort(input, n, sizeof(int), compare); // 오름차순 정렬

    dfs(0); // 아직 탐색 전. 깊이 = 0
    return 0;
}