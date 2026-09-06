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

class MyLinkedList{ // user defined data structure
private:   
    Node* head;
    Node* tail;
    int length;
public:
    MyLinkedList(){
        head = tail = NULL;
        length = 0;
    }
    void addAtTail(int val){
        Node* n = new Node(val);
        if(length == 0) head = tail = n;
        else{
            tail->next = n;
            tail = n;
        }
        length++;
    }
    void addAtHead(int val){
        Node* n = new Node(val);
        if(length == 0) head = tail = n;
        else{
            n->next = head;
            head = n;
        }
        length++;
    }
    void add(int idx, int val){
        if(idx<0 || idx>length){
            cout<<"Invalid Index!";
            return;
        }
        if(idx == 0){
            addAtHead(val);
            return;
        }
        if(idx == length){
            addAtTail(val);
            return;
        }
        Node* n = new Node(val);
        Node* temp = head;
        for(int i=1;i<=idx-1;i++){
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
        length++;
    }
    void removeAtHead(){
        if(length == 0){
            cout<<"Linked List is Empty!"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        length--;
        delete(temp);
    }
    void remove(int idx){
        if(idx<0 || idx>=length){
            cout<<"Invalid Index!";
            return;
        }
        if(idx == 0){
            removeAtHead();
            return;
        }
        Node* temp = head;
        for(int i=1;i<idx;i++){
            temp = temp->next;
        }
        Node* toBeDeleted = temp->next;
        temp->next = temp->next->next;
        if(idx == length-1) tail = temp; // IMPORTANT
        length--;
        delete(toBeDeleted);
    }
    int get(int idx){
        if(idx<0 || idx>=length){
            cout<<"Invalid Index!";
            return -1;
        }
        if(idx == length-1) return tail->val;
        Node* temp = head;
        for(int i=1;i<=idx;i++) 
            temp = temp->next;
        return temp->val;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    int size(){
        return length;
    }
};

int main(){
    MyLinkedList ll;
    ll.addAtTail(10);
    ll.addAtTail(20);
    ll.addAtTail(30);
    ll.display();
    ll.removeAtHead();
    ll.display();
    ll.addAtHead(40);
    ll.display();
    // ll.length = 0; // error
    ll.addAtTail(60);
    ll.display();
    cout<<ll.size()<<endl;
}