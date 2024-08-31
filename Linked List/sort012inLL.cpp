#include<bits/stdc++.h>
using namespace std;
class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}



// this is the code when overriding the llinked list is not allowed
Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}


// this is the code when overriding the llinked list is allowed
Node* sort(Node* head){
    if(head == NULL || head->next == NULL)
        return head;
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* curr = head;
    while(curr!= NULL){
        if(curr->data == 0)
            zeroCount++;
        else if(curr->data == 1)
            oneCount++;
        else
            twoCount++;
        curr = curr->next;
    }
    curr = head;
    while(curr!=NULL){
        if(zeroCount > 0){
            curr->data = 0;
            zeroCount--;
        }
        else if(oneCount > 0){
            curr->data = 1;
            oneCount--;
        }
        else{
            curr->data = 2;
            twoCount--;
        }
        curr = curr->next;
    }
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to create a new node and append it to the list
void append(Node*& head, int data) {
    if (head == nullptr) {
        head = new Node(data);
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
}

int main() {
    // Create an unsorted linked list containing 0s, 1s, and 2s
    Node* head = nullptr;
    append(head, 2);
    append(head, 1);
    append(head, 0);
    append(head, 2);
    append(head, 1);
    append(head, 0);
    append(head, 2);
    append(head, 1);
    append(head, 0);

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Sort the list
    head = sort(head);

    // Print the sorted list
    cout << "Sorted list: ";
    printList(head);

    return 0;
}