//print nth from end in linke,d list
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};
Node* nthElement(Node*&head,int n){
    Node* slow = head;
    Node* fast = head;
    for(int i = 0; i<n-1; ++i){ // we have started from head thats why stopping condition is n-1
        if(fast == NULL){
            cout<<"Invalid input, nth element does not exist."<<endl;
            return NULL;
        }
        fast = fast -> next;
    }
    while(fast->next!= NULL){
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}
void insertAtTail(Node*& head,int value){
    Node* newNode = new Node(value);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp -> next!= NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    int n;
    Node* head = NULL;
    cout<<"Enter the number of elements: "<<endl;
    int size;
    cin>>size;
    int value;
    for(int i = 0; i<size ; ++i){
        cout<<"Enter the value of the element to insert at tail"<<endl;
        cin>>value;
        insertAtTail(head,value);
    }
    cout<<"Enter the number of element from end"<<endl;
    cin>>n;

    Node* result = nthElement(head,n);
    if (result){
        cout<<"The "<<n<<"th element from end is: "<<result->data<<endl;
    }
    return 0;
}