#include <bits/stdc++.h>
using namespace std;

class Node {
        public :

        int data;
        Node *next;
        Node *random;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }
    };

void insertAtTail(Node* &ansHead , Node* &ansTail, int digit){
    Node* newNode = new Node(digit);
    
    if(ansHead == NULL){
        ansHead = ansTail = newNode;
    }else{
        ansTail -> next = newNode;
        ansTail = newNode;
    }
}

Node *copyList(Node *head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node*temp = head;
        
        //step 1: copy list with normal pointers
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        
        //step 2:create a map
        unordered_map<Node*,Node*> oldToNew;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode!=NULL){
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        //reset to heads
        originalNode = head;
        cloneNode = cloneHead;
        
        //Assigning random pointers in clone list 
        //map structure
        //oldToNew[originalNode] gives us the value of cloneNode on which it is mapped
        //originalNode and cloneNode are addresses
        //So if wee want to find random pointer of the current cloneNode it will be as same
        //as originalNode random pointer.So cloneNode->random = oldToNew[originalNode->random]
        while(originalNode!=NULL){
            cloneNode->random =  oldToNew[originalNode->random];
             originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
        
    }

void print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

//This approach has space complexity of O(1)
Node *copyListApproach2(Node *head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node*temp = head;
        
        //step 1: copy list with normal pointers
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        
        //step 2 : add clone nodes between original nodes
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode!=NULL){
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode =next;
            
            //same for clone list
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
        
        //step 3 : Radnom pointer copy
        temp = head;
        while(temp != NULL){
            if(temp->next!=NULL){
                temp->next->random = temp->random?temp->random->next:temp->random;
            }
            temp= temp->next->next;
            
            /* or 
            if(temp->next !=NULL{
                If(Temp->random!=NULL{
                    temp->next->random = temp->random->next;
                }
                else{
                    temp->next->random = temp->random;
                }
            }
            temp= temp->next->next;
            
            */
        }
        
        //step 4 : Revert chnages in step 2
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode!=NULL){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            //same for clone list
            if(originalNode !=NULL){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        return cloneHead;
        
        
    }
int main() {
    // Create an unsorted linked list with duplicates
    // Example: 5 -> 1 -> 3 -> 2 -> 5 -> 3 -> 4 -> 1
    Node* head = new Node(5);
    head->next = new Node(1);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next->next = new Node(1);
    
    // Call the function to clone the linked list
    Node* cloneHead = copyList(head);
    
    // Print the cloned linked list
    print(head);
    print(cloneHead);
    
    // Delete the original and cloned linked lists to free up memory
    while(head!= NULL){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    while(cloneHead!= NULL){
        Node* temp = cloneHead;
        cloneHead = cloneHead->next;
        delete temp;
    }
    

    return 0;
}
