#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
level: y. parent > child
x left < right
pre: Rlr
post: lrR
*/

typedef struct Node{
    int x, y, idx;
    Node *l, *r;
}Node;

void make_tree(Node* parent, Node* child){
    if(child -> x < parent -> x){
        if(parent -> l == NULL){
            parent -> l = child;
            return;
        }
        make_tree(parent -> l, child);
    }
    else{
        if(parent -> r == NULL){
            parent -> r = child;
            return;
        }
        make_tree(parent -> r, child);
    }
}

void preorder(Node* node, vector<int>& pre){
    if(node == NULL) return;
    
    pre.push_back(node -> idx);
    preorder(node -> l, pre);
    preorder(node -> r, pre);
}

void postorder(Node* node, vector<int>& post){
    if(node == NULL) return;
    
    postorder(node -> l, post);
    postorder(node -> r, post);
    post.push_back(node -> idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    int n = nodeinfo.size();
    vector<Node> tree;
    for(int i = 0; i < n; i++){
        tree.push_back({nodeinfo[i][0], nodeinfo[i][1], i + 1, NULL, NULL});
    }
    
    sort(tree.begin(), tree.end(), [](const auto& a, const auto& b){
        if(a.y != b.y) return a.y > b.y;
        return a.x < b.x;
    });
    
    for(int i = 1; i < n; i++) make_tree(&tree[0], &tree[i]);
    
    vector<int> pre, post;
    preorder(&tree[0], pre);
    postorder(&tree[0], post);
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}