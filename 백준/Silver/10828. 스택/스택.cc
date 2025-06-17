#include <stdio.h>
#include <string.h>

#define MAX 10000

int stack[MAX];
int top = -1;

void Push(int);
int Pop();
int Size();
int Empty();
int Top();

int main(){
    int n;
    scanf("%d", &n);
    char command[6] = {0,}; // NULL
    for(int i = 0; i < n; i++){
        scanf("%s", command);
        if(!strcmp(command, "push")){
            int x;
            scanf("%d", &x);
            Push(x);
        }
        else if(!strcmp(command, "pop")){
            printf("%d\n", Pop());//empty stack, return -1
        }
        else if(!strcmp(command, "size")){
            printf("%d\n", Size());
        }
        else if(!strcmp(command, "empty")){
            if(Empty()) printf("1\n");//empty O, return 1
            else printf("0\n");// return 0
        }
        else if(!strcmp(command, "top")){
            printf("%d\n", Top());//empty stack, return -1
        }
    }

    return 0;
}

void Push(int x){
    stack[++top] = x;
    return;
}

int Pop(){
    if(Empty()) return -1;
    return stack[top--];
}

int Size(){
    return (top + 1);
}

int Empty(){
    if(top < 0) return 1;
    else return 0;
}

int Top(){
    if(Empty()) return -1;
    return stack[top];
}