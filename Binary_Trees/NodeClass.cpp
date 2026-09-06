#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};
void print(Node* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}
int getSize(Node* root){
    if(root == NULL) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}
int product(Node* root){
    if(root == NULL) return 1;
    return root->val * product(root->left) * product(root->right);
}
int levels(Node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}
int main(){
    Node* a = new Node(1); // root
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->left = f; c->right = g;

    cout<<getSize(a)<<endl;
    cout<<levels(a)<<endl;
    print(a);
}