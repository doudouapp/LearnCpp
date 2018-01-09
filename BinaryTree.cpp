#include<iostream>

struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;

void insert(int data) {
    struct node *t = new node;
    struct node *cur;
    struct node *par;

    t -> data = data;
    t -> leftChild = NULL;
    t -> rightChild = NULL;
    if (root == NULL) {
        root = t;
    } else {
        cur = root;
        par = NULL;
        while(1) {
            par = cur;
            if (data < par -> data) {
                cur = cur -> leftChild;
                if (cur == NULL) {
                    par -> leftChild = t;
                    return;
                }
            } else {
                cur = cur -> rightChild;
                if (cur == NULL) {
                    par-> rightChild = t;
                    return;
                }
            }
        }
    }
}

struct node* search(int data) {
    struct node *cur = root;
    while (cur -> data != data) {
        if (cur -> data > data) {
            cur = cur -> leftChild;
        } else {
            cur = cur -> rightChild;
        }
        if (cur == NULL) {
            return NULL;
        }
    }
    return cur;
}

// 前序遍历
void pre_order_traversal(struct node* root) {
    if (root != NULL) {
        std :: cout << root -> data << " ";
        pre_order_traversal(root -> leftChild);
        pre_order_traversal(root -> rightChild);
    }
}

// 后序遍历
void post_order_traversal(struct node* root) {
    if(root != NULL) {
    post_order_traversal(root -> leftChild);
    post_order_traversal(root -> rightChild);
    std :: cout << root -> data << " ";
    }
}

int main() {

    using namespace std;
    int array[7] = { 27,14,35,10,19,31,42 };
    
    for (int i = 0; i < 7; i++) {
        insert(array[i]);
    }

    pre_order_traversal(root);
    cout << '\n';
    // post_order_traversal(root);
    return 0;
}