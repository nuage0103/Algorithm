#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int x;
    Node *l, *r;
}Node;

vector<int> pre, in;

Node* make_tree(int preL, int preR, int inL, int inR){
    if(!(preL <= preR && inL <= inR)) return NULL;

    int root_val = pre[preL];
    Node* root = new Node{root_val, NULL, NULL};

    int in_root = find(in.begin() + inL, in.begin() + inR + 1, root_val) - in.begin();
    int l_size = in_root - inL;

    root -> l = make_tree(preL + 1, preL + l_size, inL, in_root - 1);
    root -> r = make_tree(preL + 1 + l_size, preR, in_root + 1, inR);

    return root;
}

void post(Node* v){
    // l, r, R
    if(v == NULL) return;

    post(v->l);
    post(v->r);
    cout << v->x << ' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        pre.clear();
        in.clear();

        int n;
        cin >> n;
        pre.resize(n);
        in.resize(n);
        for(int i = 0; i < n; i++) cin >> pre[i];
        for(int i = 0; i < n; i++) cin >> in[i];

        Node* root = make_tree(0, n-1, 0, n-1);
        post(root);
        cout << '\n';
    }

    return 0;
}
