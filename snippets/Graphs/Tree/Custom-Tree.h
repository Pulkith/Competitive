#include <bits/stdc++.h>

using namespace std;

struct Node {
    char val;
    int data;
    Node* left;
    Node* right;
    Node* parent;
    bool isLeft;

    Node(char v, int d, bool L) {
        val = v;
        data = d;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        isLeft = L;
    }
};
//1 Indexed
struct Tree {
    Node* root;
    int height;
    long long total;
    vector<Node*> tree;

    void Build(int height) {
        this->height = height;
        total = (1LL << this->height) - 1;
        tree.clear();
        tree.resize(total+1);
    }
    void add(int node_number, Node &node) {
        if(node_number == 1) {
            tree[1] = &node;
            root = &node;
        }
        else {
            if(node_number&1) (tree[node_number / 2])->left = &node;
            else (tree[node_number/2])->right = &node;
            tree[node_number] = &node;
            tree[node_number]->parent = tree[node_number/2];
        }
    }   

    Node* query(int index) {
        return tree[index];
    }

    void update(Node* cur){
        //Update Current Node


        if(cur->parent != nullptr) update(cur->parent);
    }
};