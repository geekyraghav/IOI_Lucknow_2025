#include<iostream>
using namespace std;
class Node{ // user defined data type
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next = NULL;
    }
};
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int length(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void display(Node* head){
    if(head == NULL) return;
    display(head->next);
    cout<<head->val<<" ";
}
int main(){
    Node* a = new Node(10);
    // cout<<(*a).next<<endl;
    // cout<<a->val<<endl;
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    cout<<a->val<<endl;
    cout<<a->next->val<<endl;
    cout<<a->next->next->val<<endl;

    print(a);
    cout<<length(a)<<endl;
    display(a);
}